package org.example.Service;

import org.example.Domain.DTOs.FriendDTO;
import org.example.Domain.Entity;
import org.example.Domain.Friendship;
import org.example.Domain.Tuple;
import org.example.Domain.User;
import org.example.Exception.ServiceException;
import org.example.Repository.Repository;

import java.time.LocalDateTime;
import java.util.*;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.StreamSupport;

import static java.lang.Integer.MIN_VALUE;

public class FriendService implements Service<Long>{
    private final Repository userRepo;
    private final Repository friendshipRepo;
    public Set<User> set;
    private final String type;

    public FriendService(Repository userRepo, Repository friendshipRepository,String type) {
        this.userRepo = userRepo;
        this.friendshipRepo=friendshipRepository;
        this.type=type;
    }
    /*
    Add/Remove User
     */
    @Override
    public boolean addUser(String firstName, String lastName, String userName) {
        User NewUser=new User(firstName,lastName,userName);
        userRepo.save(NewUser);
        return true;
    }
    @Override
    public Entity<String> removeUser(String username) {
        User foundUser=findbyUsername(username);
        //REMOVE THEM FROM FRIENDSHIPS!
        if(foundUser==null)
        {
            throw new ServiceException("User was not found!");
        }
        if(Objects.equals(type, "InMemory"))
        {
            List<User> friends=new ArrayList<>(foundUser.getFriends());
            friends.forEach(friend->removeFriendship(foundUser.getUsername(),friend.getUsername()));
            foundUser.getFriends().clear();
        }
        //old ver
//        if(foundUser.getFriends()!=null)
//        {
//            ArrayList<User> friends=foundUser.getFriends();
//            int nrFriends=friends.size();
//            while (nrFriends!=0)
//            {
//                removeFriendship(foundUser.getUsername(),friends.get(0).getUsername());
//                nrFriends--;
//            }
//
//        }

        Optional<Entity<String>> deletedUser=userRepo.delete(foundUser.getId());
        return deletedUser.get();

    }


    /*
    ADD/REMOVE FRIENDSHIP
     */
    @Override
    public boolean addFriendship(String username1, String username2) {

        User user1=findbyUsername(username1);
        User user2=findbyUsername(username2);
        Friendship friendship=new Friendship(user1, user2, LocalDateTime.now());
        //creez friendship dar trebuie sa il si adaug
        friendshipRepo.save(friendship);
       if(type.equals("InMemory"))
       {
           addFriendtoUsers(user1,user2);}
        return true;
    }

    @Override
    public boolean removeFriendship(String username1, String username2) {
        User user1=findbyUsername(username1);
        User user2=findbyUsername(username2);

        Friendship friendship=findFriendship(user1,user2);
        if(friendship==null)
        {
            throw new ServiceException("The friendship was not found!:(");
        }
        if(type.equals("InMemory"))
        {
            BiConsumer<User, User> updateUserFriends = (u1, u2) -> {

                ArrayList<User> newFriends = u1.getFriends();
                if (!newFriends.isEmpty()) {
                    newFriends.remove(u2);
                    u1.setFriends(newFriends);
                    userRepo.update(u1);
                }

            };
            updateUserFriends.accept(user1, user2);
            updateUserFriends.accept(user2, user1);
//        ArrayList<User> friendshipListuser1=user1.getFriends();
//        ArrayList<User> friendshipListUser2=user2.getFriends();
//        friendshipListuser1.remove(user2);
//        friendshipListUser2.remove(user1);
//        user1.setFriends(friendshipListuser1);
//        user2.setFriends(friendshipListUser2);
//        userRepo.update(user1);
//        userRepo.update(user2);
        }
        friendshipRepo.delete(friendship.getId());

        return true;
    }

    //NUMBER OF COMUNITIES
    @Override
    public int showNumberofComunities() {
        Iterable<User> users=userRepo.findAll();
        set= new HashSet<>();
        //        for(User user:users)
//        {
//            if(!set.contains(user))
//            {
//                numberOfComunities++;
//                DFS(user);
//            }
//        }
        return StreamSupport.stream(users.spliterator(),false)
                .filter(user->!set.contains(user))
                .mapToInt(user->
                {   set.add(user);
                    DFS(user);
                    return 1;})
                .sum();
    }
    //BIGGEST COMMUNITIES
    @Override
    public List<List<User>> biggestCommunity() {
        List<List<User>> allCommunities=getAllCommunities();
        int max=MIN_VALUE;
        List<List<User>> biggestCommunities=new ArrayList<>();
        for (List<User> community:allCommunities)
        {
            int RouteSize=longestPath((ArrayList<User>) community);
            if(RouteSize>max)
            {
                biggestCommunities.clear();
                max=RouteSize;
                biggestCommunities.add(new ArrayList<>(community));
            }
            else if(RouteSize==max)
            {
                biggestCommunities.add(new ArrayList<>(community));
            }
        }
        return biggestCommunities;
    }

    //METHODS USED FOR THE MAIN FUNCTIONS
    public   User findbyUsername(String username)
    {
        return (User) StreamSupport.stream(userRepo.findAll().spliterator(),false)
                .filter(user->((User)user).getUsername().equals(username))
                .findFirst()
                .orElse(null);
//        Iterable allUsers=userRepo.findAll();
//        for (Object o:allUsers
//        ) {
//            if(((User) o).getUsername().equals(username))
//                return (User) o;
//        }
//        return null;

    }
    private void addFriendtoUsers(User u1, User u2)
    {
        //SO, I need to check if they have friends or not so I can modify the list of friends they have!
        //For each friend I need to check and then create a new ArrayList with the new Friends!
        //User u1 :
        ArrayList<User> newFriends1 = new ArrayList<>(u1.getFriends());
        ArrayList<User> newFriends2 = new ArrayList<>(u2.getFriends());
        if(newFriends1.contains(u2))
        {

            throw new ServiceException("They are already friends:)!");

        }

        newFriends1.add(u2);
        //User u2:


        if(u2.getFriends().contains(u2))
        {
            throw new ServiceException("They are already friends:)!");
        }
        newFriends2.add(u1);
        //Here I work with copy of users. So with the new Lists I have I can set the new friends :)
        u1.setFriends(newFriends1);
        u2.setFriends(newFriends2);
        //Now I just use my update . Any exceptions there were found will be thrown by the repo!
        userRepo.update(u1);
        userRepo.update(u2);

    }
    private Friendship findFriendship(User user1, User user2) {

        Tuple<Long,Long> id=new Tuple<>(user1.getId(),user2.getId());
        if(type.equals("InMemory"))
        {
            Optional<Friendship> friendship= friendshipRepo.findOne(id);
            if(friendship.isEmpty())
            {
                Tuple<Long,Long> id2=new Tuple<>(user2.getId(),user1.getId());
                friendship=friendshipRepo.findOne(id2);
            }
            return friendship.get();
        }
        else {return (Friendship) friendshipRepo.findOne(id).get();}


    }
    static class Pair<T,V> {
        T first; // maximum distance Node
        V second; // distance of maximum distance node

        //Constructor
        Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }
    }
    private LinkedList<Integer>[] getAdjList(Map<User,Integer> perechi,int V)
    {
        LinkedList<Integer>[] adj;//Lista de adiacenta
        adj=new LinkedList[V];
        IntStream.range(0,V).forEach(i->adj[i]=new LinkedList<>());
//        for(int i=0;i<V;++i)
//        {
//            adj[i]=new LinkedList<Integer>();
//        }
//        perechi.forEach((user,userIndex)->user.getFriends()
//                .forEach(friend->
//                {
//                    int friendIndex=perechi.get(user).intValue();
//                    adj[userIndex].add(friendIndex);
//                }));
        if(type.equals("InMemory"))
        {
            perechi.keySet().forEach(user -> user.getFriends().forEach(user1 -> adj[perechi.get(user)].add(perechi.get(user1))));
        }
        else
        {
            perechi.keySet().forEach(user -> getFriendships(user).forEach(user1 -> adj[perechi.get(user)].add(perechi.get(user1))));

        }
//        for (User user:perechi.keySet())
//        {
//            for(User userFriend:user.getFriends())
//            {
//                adj[perechi.get(user).intValue()].add(perechi.get(userFriend));
//            }
//        }
        return adj;
    }
    private Pair<Integer,Integer> BFS(int u,int V,LinkedList<Integer>[] adj)
    {
        int [] dis=new int[V];
        Arrays.fill(dis,-1);
        Queue<Integer> q=new LinkedList<>();
        q.add(u);
        dis[u]=0;
//        while(!q.isEmpty())
//        {
//            int t=q.poll();
//            for(int i=0;i<adj[t].size();++i)
//            {
//                int v=adj[t].get(i);
//                if(dis[v]==-1)
//                {
//                    q.add(v);
//                    dis[v]=dis[t]+1;
//                }
//            }
//        }
//        int maxDis=0;
//        int nodeIdx=0;
//        for(int i=0;i<V;++i)
//        {
//            if(dis[i]>maxDis)
//            {
//                maxDis=dis[i];
//                nodeIdx=i;
//            }
//        }
//        return new Pair<>(nodeIdx, maxDis);

        while (!q.isEmpty()) {
            int t = q.poll();
            Arrays.stream(adj[t].toArray(new Integer[0]))
                    .filter(v -> dis[v] == -1)
                    .forEach(v -> {
                        q.add(v);
                        dis[v] = dis[t] + 1;
                    });
        }

        int[] result = new int[] { 0, 0 };
        IntStream.range(0, V)
                .filter(i -> dis[i] > result[1])
                .forEach(i -> {
                    result[0] = i;
                    result[1] = dis[i];
                });

        return new Pair<>(result[0], result[1]);
    }
    public int longestPath(ArrayList<User> nodes)
    {
        //lucrez ca pe un graf pentru a determina cat e cel mai mare path ca lungime
        int V=nodes.size();
        //Map<User,Integer> perechi=new HashMap<>();
        Integer value=0;
        Map<User, Integer> perechi = IntStream.range(0, V)
                .boxed()
                .collect(Collectors.toMap(nodes::get, i -> i));
//        for(User user:nodes)
//        {
//
//            perechi.put(user,value);
//            value+=1;
//        }
        LinkedList<Integer>[] adj=getAdjList(perechi,V);
        Pair<Integer,Integer> t1,t2;
        t1=BFS(0,V,adj);
        t2=BFS(t1.first,V,adj);
        return t2.second;
    }
    public List<User> getFriendships(User u)
    {
        List<Optional<User>> friends=new ArrayList<>();
        Iterable <Friendship> friendships=friendshipRepo.findAll();

        return StreamSupport.stream(friendships.spliterator(),false).
                filter(friendship -> Objects.equals(friendship.getId().getRight(), u.getId()) || Objects.equals(friendship.getId().getLeft(), u.getId()))
                .map(friendship ->
                {
                    if(Objects.equals(friendship.getId().getLeft(), u.getId()))
                        return userRepo.findOne(friendship.getId().getRight()).orElse(null);
                    else
                        return userRepo.findOne(friendship.getId().getLeft()).orElse(null);
                }).filter(Objects::nonNull).map(element->(User)element).collect(Collectors.toList());
    }

    private ArrayList<User> DFS(User user) {
        ArrayList<User> community=new ArrayList<>();
        community.add(user);
        set.add(user);
        //i traverse all of its friends that have not been traversed before
        if(type.equals("InMemory"))
        {
            user.getFriends().stream().
                    filter(friend->!set.contains(friend)).
                    forEach(friend->{
                        ArrayList<User> newL=DFS(friend);
                        community.addAll(newL);
                        }
                        );
        }
        else
        {
            getFriendships(user).stream().
                    filter(friend->!set.contains(friend)).
                    forEach(friend->{
                                ArrayList<User> newL=DFS(friend);
                                community.addAll(newL);
                            }
                    );
        }
//        for (User friend:user.getFriends())
//        {
//            if(!set.contains(friend))
//            {
//                ArrayList<User> newL=DFS(friend);
//                for (User friendsInCommon:newL)
//                {
//                    community.add(friendsInCommon);
//                }
//            }
//        }
        return community;
    }

    /**
     * Get all users
     * @return users
     */
    @Override
    public Iterable getAllUsers() {
        return userRepo.findAll();
    }

    /**
     * Get all friendships
     * @return friendships
     */
    @Override
    public Iterable getAllFriendships() {
        return friendshipRepo.findAll();
    }

    /**
     * Get all communities
     * @return communities of people
     */
    public List<List<User>> getAllCommunities()
    {
        Iterable<User> users=userRepo.findAll();
        List<List<User>> communities;
        set= new HashSet<>();
        communities=StreamSupport.stream(users.spliterator(),false)
                .filter(user->!set.contains(user)).
                map(this::DFS).
                collect(Collectors.toList());

//        for(User user:users)
//        {
//            if(!set.contains(user))
//            {
//
//                communities.add(DFS(user));
//            }
//        }
        return communities;
    }
    void validateDate(int year,int month)
    {
        if(year<0)
        {
            throw new ServiceException("Year cannot be negative!");
        }
        boolean error=false;
        if(month<1||month>12)
        {
            throw new ServiceException("Invalid month!");
        }

    }
    public List<FriendDTO> getFriendshipsByMonth(String username,int year,int month)
    {
        validateDate(year,month);

        User user=findbyUsername(username);
        if(user==null)
        {
            throw new ServiceException("User with username "+username+" does not exist!");
        }
        Iterable<Friendship> friendships=friendshipRepo.findAll();

        return StreamSupport.stream(friendships.spliterator(),false).
                filter(friend->{
                    LocalDateTime time=friend.getDate();
                    return (time.getMonthValue()==month)&&(time.getYear()==year);
                }).
                map(friendship -> {
                    
                    if(Objects.equals(friendship.getId().getLeft(), user.getId()))
                    {
                        return new FriendDTO((User) (userRepo.findOne(friendship.getId().getRight())).get(),
                                friendship.getDate());
                    }
                    else if(Objects.equals(friendship.getId().getRight(), user.getId()))
                    {
                        return new FriendDTO((User) (userRepo.findOne(friendship.getId().getLeft())).get(),
                                friendship.getDate());
                    }
                    return null;
                }).map(o -> (FriendDTO) o).collect(Collectors.toList());
    }

}
