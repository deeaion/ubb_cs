
/*TOT CE INSEAMNA OM*/

/*

	INSERTING ADRESSES
*/
INSERT INTO PersonalAddress (street,city,zip,county_state,type,numar) VALUES ('Avram Iancu','Floresti','407280','Cluj','Online',10);
INSERT INTO PersonalAddress(type) VALUES ('IN_STORE');
INSERT INTO PersonalAddress(street,city,zip,county_state,type,numar) VALUES ('Principatele Unite','Bucuresti','040165','Bucuresti','Online',64);
INSERT INTO PersonalAddress(street,city,zip,county_state,type,numar,apartment) VALUES ('Pantelimon','Bucuresti','21631','Bucuresti','Online',27,11);
INSERT INTO PersonalAddress(street,city,zip,county_state,type,numar,apartment) VALUES ('Hasdeu','Cluj-Napoca','400371','Cluj','Online',27,11);
SELECT * FROM PersonalAddress;
SELECT * FROM PersonalInformation;

/*Personal Information*/

INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Ana','Maria',6231020285391,'0744496477',4);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Ana','Ray',2910803240101,'0790896477',3);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Clara','Ray',1970208386041,'0792496477',2);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Lara','Rain',1880526125352,'0790896900',3);

INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Bob','Bran',6020410110229,'0790896400',2);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Paul','Johnson',5041102424133,'0790000477',2);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Chris','Bang',2961102302470,'0231537747',3);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Peter','Mound',6050621328123,'0790896980',5);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Sky','Fall',2971227118644,'0790896777',1);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Trying','Hope',6040710082349,'0712345678',1);
INSERT INTO PersonalInformation(first_name,last_name,CNP,mobile_phone,id_address) VALUES ('Trying2','Hope2',6030710082349,'071234678',5);

/*Employees*/
INSERT INTO Employee(id_person,email,badge_number) VALUES (3,'clararay@gmail.com','AX2311');
INSERT INTO Employee(id_person,email,badge_number) VALUES (2,'ana_ray@gmail.com','AX2111');
INSERT INTO Employee(id_person,email,badge_number) VALUES (9,'likeaskyfall@yahoo.com','AX1891');
SELECT * FROM Employee;

/*MANAGER*/

INSERT INTO Manager(id_person,email,badge_number) VALUES(7,'chrisbang@yahoo.com','MX310');

SELECT * FROM Manager;

INSERT INTO Client(id_person,username,starts_at) VALUES (1,'anaMar','2022-11-11');
INSERT INTO Client(id_person,username,starts_at) VALUES (4,'lara_Rain','2022-08-10');
INSERT INTO Client(id_person,username,starts_at) VALUES (5,'bobha','2022-11-02');
INSERT INTO Client(id_person,username,starts_at) VALUES (6,'paulJ97','2021-12-09');
INSERT INTO Client(id_person,username,starts_at) VALUES (8,'PeterMound','2022-11-18');
INSERT INTO Client(id_person,username,starts_at) VALUES (10,'plswork','2022-11-19');
INSERT INTO Client(id_person,username,starts_at) VALUES (11,'plswork2','2023-10-20');

SELECT * FROM Client;
SELECT * FROM Employee;
SELECT * FROM ClientEmployeeInteraction;
/*INTERACTIUNI CLIENT EMPLOYEE)
*/
INSERT INTO ClientEmployeeInteraction(id_client,id_employee,date_of_interaction) VALUES
(1,1,'2023-10-08'),
(1,2,'2023-11-09'),
(5,3,'2023-09-12'),
(4,2,'2023-11-23');
SELECT * FROM ClientEmployeeInteraction;
SELECT * from TypeOfGroup
INSERT INTO TypeOfGroup VALUES
('Rock','Boy Group',6),
('R&B','Girl Group',4),
('Pop','Mixed Group',4),
('Rock','Boy Group',8),
('Mixed','Boy Group',8);
/* GROUP*/
select * from band
INSERT INTO Band(group_name,debut_date,records_number,id_typeofgroup) VALUES
('Stray Kids','2018-05-25',50,5),
('Ateez','2018-10-24',12,5),
('Itzy', '2019-02-12',8,4),
('(G)-IDLE','2018-05-02',20,4),
('BTS','2013-06-13',35,2),
('SEVENTEEN','2015-05-26',30,4),
('TWICE','2015-10-20',20,2),
('P1Harmony','2020-10-28',10,1),
('NCT','2016-04-04',30,1),
('NCT 127','2016-07-07',10,2),
('NCT U',' 2016-04-04',10,3),
('NCT Dream',' 2016-08-25',10,4),
('Red Velvet','2014-08-01',30,5),
('Mamamoo','2014-06-19',20,2),
('Blackpink','2016-08-08',20,3);

INSERT INTO Artist(first_name,last_name,stage_name) VALUES
('Mi-yeon','Cho','Miyeon'),
('Hye-jin','Ahn','Hwasa'),
('Yong-sun','Kim','Solar'),
('Jung-kook','Jeon','Jungkook'),
('Yoon-gi','Min','Suga'),
('Ji-Min','Park','Jimin'),
('Ho-Seok','Jung','J-Hope'),
('Tae-yong','Lee','Taeyong'),
('Christian','Yu','Dpr Ian'),
('Ji-Hyo','Park','Jihyo'),
('Na-eyon','Im','Nayeon'),
('Lalisa','Manoban','Lisa');
SELECT * FROM Artist;
SELECT * From Band;
/*artist*/
INSERT INTO GroupMembersInfo(id_artist,id_group,position) VALUES
(2,14,'dancer'),
(3,14,'singer'),
(1,4,'rapper'),
(4,5,'dancer'),
(5,5,'rapper'),
(6,5,'singer'),
(7,5,'rapper'),
(8,9,'dancer'),
(8,10,'rapper'),
(8,11,'rapper'),
(10,7,'dancer'),
(11,7,'singer'),
(12,15,'dancer');
use KpopStore;
SELECT * FROM GroupMembersInfo;
/*
	producTS CATEGORY
*/
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Season Greeting','Japan');
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Season Greeting','Korea');
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Album','Korea');
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Merchandise','Japan');
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Merchandise','China');
INSERT INTO ProductCategory(categ_name,branch_country) VALUES ('Album','Japan');
SELECT * FROM ProductCategory;

/*PRODUSE*/

INSERT INTO Product(id_category,product_Name,pr_version,price) VALUES
(3,'5 Star','A',120),
(3,'5 Star','Limited',160),
(3,'5 Star','B',120),
(3,'Outlaw','Z',135),
(6,'Social Path','A',200),
(4,'Skzoo','Tour 5-Star Version',200),
(3,'Zone','Z',150),
(6,'Ringo','Limited A',365),
(4,'2024 Season Greeting NCT',NULL,400);
SELECT * FROM Product;
SELECT * FROM Client;
SELECT * FROM PersonalInformation;
SELECT * FROM PersonalAddress;
INSERT INTO ProductInventory(id_productInventory,quantity,created_at) VALUES
(1,1000,'2023-05-10'),
(2,1200,'2023-05-10'),
(3,1220,'2023-05-10'),
(4,1500,'2023-05-20'),
(5,800,'2023-08-23'),
(6,400,'2023-09-10'),
(7,2000,'2023-08-01'),
(8,700,'2023-10-02'),
(9,00,'2023-10-24');
SELECT * FROM ProductInventory;
INSERT INTO ProductDescription(normal_description,pre_order_benefits,id_productDescription) VALUES
('Photobook,Photocards,OOTD Mini Poster,Sticker Set,CD-R,Cartoon Postcard',
'B-Cut Film Mini Photobook,Folded Poster',1),
('Photobook,Photocards,OOTD Mini Poster,Sticker Set,CD-R,Cartoon Postcard,Special Folded Poster,B-Cut Film Postcard',
'B-Cut Film Mini Photobook,Folded Poster',2),
('Photobook,Photocards,OOTD Mini Poster,Sticker Set,CD-R,Cartoon Postcard',
'B-Cut Film Mini Photobook,Folded Poster',3),
('Disc + Envelope,Team Label,Book,Mark,Emergency Kit,Partner Card,Photocard, Action Card','Autographed Polaroid',4),
('CD,Photobook,2 Photocards,1 Sticker',NULL,5),
('10cm Plush Material Polyester','Photocard 1EA',6),
('Photo Book,CD-R,Photocard,Message Postcard,Interview Minibook,Bookmark,Lyrics Sticker Pack,
Folded Poster','Photo Film,
Poster',7),
('Desk Calendar, Hard Cover Diary,
Folded Poster Set,
A4 Poster Set,
Stickers,ID Card','Special Photocard',9);
SELECT id_product FROM Product;

INSERT INTO ClientOrder(id_client,id_address,mobilePhone,total_sum,finalized_at) VALUES

	(1,2,NULL,700,'2023-10-20'),
	(1,2,NULL,800,'2023-11-20'),
	(1,4,'0744496477',1000,'2023-09-20'),
	(1,4,'0744496477',100,'2023-10-10'),
	(5,2,NULL,300,'2023-10-10'),
	(3,5,NULL,200,'2023-09-10');
SELECT * FROM ClientOrder;
SELECT * FROM Product;
INSERT INTO OrderedProduct(id_order,id_product,quantity) VALUES
	(1,1,1),
	(1,2,3),
	(1,3,1),
	(2,9,1),
	(2,8,1),
	(2,3,1),
	(3,6,5),
	(4,1,1),
	(5,7,2),
	(6,5,1);

SELECT * FROM ClientOrder;
INSERT INTO Payment(id_payment,bank,payment_type) VALUES
	(1,'BT','CARD'),
	(2,NULL,DEFAULT),
	(3,'ING','CARD'),
	(4,'BT','CARD'),
	(5,NULL,'CASH'),
	(6,'BCR','CARD');
SELECT * FROM Product;
SELECT * FROM Band;
SELECT * FROM Artist;
INSERT INTO ProductInfo(id_product_info,barcode,releaseDate,id_group,id_artist) VALUES
	(1,'X2Hihx9MFXo82','2023-06-01',1,NULL);

INSERT INTO ProductInfo(id_product_info,barcode,releaseDate,id_group,id_artist) VALUES
	(2,'X2Hihx9MFXo82','2023-06-01',1,NULL),
	(3,'nk1hdRDOTXCak','2023-06-01',1,NULL),
	(4,'dvu7X0JTBqXHz','2023-06-20',2,NULL),
	(5,'8z2GDTSqw2Hdl','2023-08-29',1,NULL),
	(6,'RJzQ0xIsFyarV','2023-10-02',1,NULL),
	(7,'XdIMOxNUiNZr1','2023-08-03',NULL,10),
	(8,'hEDovReLTr7yZ','2023-10-01',3,NULL),
	(9,'wjLYgoiLJofz0','2023-10-20',9,NULL);




