# Album Store

Mobile App developed for the course of "Mobile Application Programming"
Labs:

- Find them:
  - [Main Repository](https://github.com/deeaion/Album-Store-Mobile-App/tree/main)
    - [Ionic 1](https://github.com/deeaion/Album-Store-Mobile-App/tree/ionic)
    - [Ionic 2](https://github.com/deeaion/Album-Store-Mobile-App/tree/ionic-2)
    - [Ionic 3](https://github.com/deeaion/Album-Store-Mobile-App/tree/ionic-3)
- Native (Android)
  - [Main Repository](https://github.com/deeaion/Album-Store-Mobile-App-Android)
    - [Native 1](https://github.com/deeaion/Album-Store-Mobile-App-Android/tree/Android-1)
    - [Native 2](https://github.com/deeaion/Album-Store-Mobile-App-Android/tree/Android-2)
    - [Native 3](https://github.com/deeaion/Album-Store-Mobile-App-Android/tree/Android-3)

## App description:

The app is made as a store for albums and for people who collect them! Not only can you order the albums but you can also create a collection to keep track of your albums.  
There is also a mini-game where you can jiggle the phone around and see all of your albums being shuffled around!

## Features:

- Login/Register - You can create an account and **login** to the app or use the app as a guest.
- Albums - You can see all the albums available in the store and order them. (only available whilst online)
- Purchase - You can purchase the albums and see the order history. (only available whilst online and logged in) . Here you can also easily pick your address from the **map**!
- Collection - You can create a collection of albums and see them in a list. (available both **offline** and online and logged in)
  - You can either pick an album that is already in the store or create a custom one by adding the picture (from the **gallery or camera**).
  - You can also delete the albums from the collection.
- Shuffle - You can shuffle the albums around by **jiggling**(use of phone sensors) the phone. (available both offline and online and logged in)
- **Security** - The app makes sure that the user is logged in to access the purchase, collection and shuffle features. It uses JWT tokens to authenticate the user.
- **Offline** - The app works offline and syncs the data when the user is back online.
- **Animations** - The app uses animations to make the user experience more enjoyable.
  -Notifications - Get Notifications when a new album is added to the store.
