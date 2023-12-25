/*
1)Orders (client,clientorder,payment)
where name starts with A%
group by payment type
having sum >=200
Tabele utilizate:
         client
          client order
           payment 
		   Calculez suma totala platita cash respectiv cart */
use KpopStore;
SELECT clI.first_name,SUM(cO.total_sum) AS Total,p.payment_type AS typeOfPayment
FROM Client AS client
INNER JOIN ClientOrder AS cO ON client.id_client=cO.id_client
INNER JOIN Payment AS p ON cO.id_order=p.id_payment
INNER JOIN PersonalInformation AS clI ON client.id_person=clI.id_person
WHERE clI.first_name LIKE 'Ana%'
GROUP BY clI.first_name,payment_type
HAVING SUM(cO.total_sum) >1000;
SELECT * FROM ClientOrder;
SELECT * FROM Client;
SELECT * FROM Payment;
/*
	Produs
nu e facut de artist ci de grup! ( WHERE )
group artistii
where product name contains a digit. 
Tabele utilizate: product, productinfo,artist,band.
Show:  Name artist
              Group artist
               Name produs 

			   only 5 star si season greeting nct au

*/
SELECT * FROM ProductInfo;
SELECT b.group_name AS 'Artist Name',
	   p.product_Name AS 'Product Name',
	   AVG(p.price) AS 'Price'
FROM ProductInfo AS pIn
INNER JOIN Band as b ON b.id_group=pIn.id_group
INNER JOIN Product AS p ON p.id_product=pIn.id_product_info
WHERE p.product_Name LIKE '%[0-9]%'
GROUP BY b.group_name,p.product_Name
HAVING AVG(p.price)>100


SELECT * from Product

/*3)
3)Clientii care
Au numele ce contin litera a where
Au adrese distincte
Stau in cluj
+username show
Tabele utilizate: client, personaladdress,personal information 
*/
use master;
/*MAY VER*/
SELECT c.username AS "Client Username",
		ad.city AS "City in Cluj",
		cI.first_name AS "Nume",
		ad.street AS "Street",
		cI.id_person AS "Id Person"
FROM PersonalInformation as cI
INNER JOIN Client c ON c.id_person=cI.id_person
INNER JOIN PersonalAddress AS ad ON cI.id_address=ad.id_address
WHERE ad.county_state='CLUJ';
SELECT * FROM Client;
SELECT * FROM PersonalInformation;
SELECT * FROM Personal;

/*
4)Interactiuniile cu clientii 
-> ( group by with whom they interracted)
-> having id_employee=2
->show client name, show employee name
Tabele utilizate: client,employee,clientemployee,personalinfo
m-n 
*/
SELECT ci.first_name AS "Client Name",
	   ci.last_name AS "Client Last Name",
       ei.first_name AS "Employee Name",
	   ei.last_name AS "Employee Last Name",
	   cei.date_of_interaction AS "Date of Interaction"
FROM ClientEmployeeInteraction as cei
INNER JOIN Employee AS e ON cei.id_employee = e.id_employee
INNER JOIN Client as c ON cei.id_client=c.id_client
INNER JOIN PersonalInformation AS ci ON c.id_person = ci.id_person
INNER JOIN PersonalInformation AS ei ON ei.id_person = e.id_person;
SELECT * FROM Employee;
SELECT * FROM Client;
SELECT * FROM ClientEmployeeInteraction;

/*
5) Un raport cu toate produsele din categoria Album ( where category is album)
numele produsului
preorder benefits( product description)
sa fie peste 1000 disponibilie ( product inventory)
Tabele utilizate: Product, Product Description, Product Inventory 
Folosesc distinct pentru ca sa nu imi apara acelasi produs de doua ori
*/
SELECT DISTINCT p.product_Name AS "Product Name",
       pd.pre_order_benefits AS "Preorder Benefits"
FROM Product AS p
INNER JOIN ProductDescription AS pd ON p.id_product = pd.id_productDescription
INNER JOIN ProductCategory AS pc ON p.id_category = pc.id_category
INNER JOIN ProductInventory AS pi ON p.id_product = pi.id_productInventory
WHERE pc.categ_name = 'Album' 
      AND pi.quantity > 1000;
/*
6) Clients who made Orders in store ( address ==2) (where)
numele client
CNP
username 
Client , order, persoanl address, personal info 
Folosesc distnct pentru ca ei sa nu fie repetati
*/
SELECT DISTINCT cI.first_name AS "Client Name",
       cI.CNP AS "CNP",
       c.username AS "Username"
FROM ClientOrder AS co
INNER JOIN PersonalAddress AS pa ON co.id_address = pa.id_address
INNER JOIN Client AS c ON co.id_client = c.id_client
INNER JOIN PersonalInformation AS cI ON cI.id_person=c.id_person
WHERE pa.id_address = 2;
SELECT * FROM ClientOrder;

/*
7) Artistii care sunt in cel putin 2 grupuri . 
artist band group members info
nume artist scena, first name, grupuriile unde sunt si in cate sunt
8) Quantity of produccts ordered . ( fol si cele care au null ordered). Si cati clienti have orderdered them. Client order, ordered product, numele produs (product) .
9)toate produsele facute de skz ( group, product,group by category, dystinct name 
*/
SELECT * FROM Artist;
SELECT * FROM GroupMembersInfo;
SELECT * FROM Band;
SELECT a.stage_name AS "Stage Name",
       a.first_name AS "First Name",
       COUNT(gm.id_artist) AS "Number of Groups"
FROM GroupMembersInfo AS gm
INNER JOIN Artist AS a ON a.id_artist = gm.id_artist
GROUP BY a.stage_name, a.first_name, gm.id_artist
HAVING COUNT( gm.id_artist) >= 2;

/*
8) Quantity of produccts ordered . ( fol si cele care au null ordered). 
 ordered product, numele produs (product) .*/
SELECT p.product_Name AS "Product Name",
       SUM(op.quantity) AS "Quantity Ordered"
FROM OrderedProduct AS op
LEFT JOIN Product AS p ON op.id_product = p.id_product
LEFT JOIN ClientOrder AS co ON op.id_order = co.id_order
GROUP BY p.product_Name;
SELECT * FROM OrderedProduct;
SELECT * FROM Product;
SELECT * FROM ClientOrder;
/*
9)toate produsele facute de skz ( group, product,group by category, dystinct name 
*/
SELECT pc.categ_name AS "Category",
       p.product_Name AS "Product Name"
FROM ProductInfo AS pI
INNER JOIN Product AS p ON p.id_product=pI.id_product_info
INNER JOIN ProductCategory AS pc ON p.id_category = pc.id_category
INNER JOIN Band AS b ON pI.id_group = b.id_group
WHERE b.group_name = 'Stray Kids'
GROUP BY pc.categ_name, p.product_Name;


/*
10)Produsele care sunt facute in alta tara decat korea,(show it tho),product name,distinct artist
*/
SELECT p.product_Name AS "Product Name",
        g.group_name AS "Group Name"
FROM Band AS g
INNER JOIN ProductInfo AS pI ON pI.id_group=g.id_group
INNER JOIN Product AS p ON p.id_product = pI.id_product_info
INNER JOIN ProductCategory as pc ON pc.id_category=p.id_category
WHERE pc.branch_country != 'Korea'
GROUP BY g.group_name,p.product_Name;





		



