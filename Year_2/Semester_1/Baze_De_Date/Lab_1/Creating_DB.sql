CREATE DATABASE KpopStore;
GO
Use KpopStore;

CREATE TABLE PersonalAddress
(
	id_address INT PRIMARY KEY IDENTITY,
	street VARCHAR(100),
	city VARCHAR(100),
	zip VARCHAR(20) ,
	apartment INT,
	county_state VARCHAR(100),
	type VARCHAR(100) DEFAULT 'IN_STORE' CHECK (Type='IN_STORE' OR Type='ONLINE'),
	numar INT,
);

CREATE TABLE PersonalInformation
(
	id_person INT PRIMARY KEY IDENTITY,
	first_name VARCHAR(100) NOT NULL,
	last_name VARCHAR(100) NOT NULL,
	CNP NUMERIC(13) NOT NULL UNIQUE,
	mobile_phone VARCHAR(13) NOT NULL UNIQUE,
	id_address INT ,
	CONSTRAINT fk_PersonAdress FOREIGN KEY (id_address) REFERENCES  PersonalAddress(id_address),


);


	
CREATE TABLE Manager
(
	id_manager INT PRIMARY KEY IDENTITY,
	id_person INT,
	badge_number VARCHAR(20) NOT NULL UNIQUE,
	email VARCHAR(200) UNIQUE,
	CONSTRAINT fk_ManagerInfomration FOREIGN KEY(id_person) REFERENCES PersonalInformation(id_person)
	);


CREATE TABLE Employee
(
	id_employee INT PRIMARY KEY IDENTITY,
	id_person INT,
	email VARCHAR(200) UNIQUE,
	badge_number VARCHAR(20) NOT NULL UNIQUE,
	CONSTRAINT fk_EmployeeInfomration FOREIGN KEY(id_person) REFERENCES PersonalInformation(id_person)
);

CREATE TABLE Client
(
	id_client INT PRIMARY KEY IDENTITY,
	id_person INT,
	username VARCHAR(100) UNIQUE,
	starts_at DATETIME,
	CONSTRAINT fk_ClientInformation FOREIGN KEY(id_person) REFERENCES PersonalInformation(id_person)

);


CREATE TABLE ClientEmployeeInteraction
(
	id_client INT FOREIGN KEY REFERENCES Client(id_client),
	id_employee INT FOREIGN KEY REFERENCES Employee(id_employee),
	date_of_interaction DATE,
	CONSTRAINT pk_Interaction PRIMARY KEY(id_client,id_employee)

	
);

CREATE TABLE Artist
(
	id_artist INT PRIMARY KEY IDENTITY,
	first_name VARCHAR(100),
	last_name VARCHAR(100),
	stage_name VARCHAR(100),
);

CREATE TABLE Band
(
	id_group INT PRIMARY KEY IDENTITY,
	group_name VARCHAR(200) NOT NULL,
	debut_date DATE,
	records_number INT
);

CREATE TABLE GroupMembersInfo
(
	id_artist INT FOREIGN KEY REFERENCES Artist(id_artist),
	id_group INT FOREIGN KEY REFERENCES Band(id_group),
	CONSTRAINT pk_MemInfo PRIMARY KEY (id_artist,id_group)


);

CREATE TABLE ProductCategory
(
	id_category INT PRIMARY KEY IDENTITY,
	categ_name VARCHAR(100) NOT NULL CHECK (categ_name='Merchandise' OR categ_name='Album' OR categ_name='Season Greeting' OR categ_name='CD+DVD'),
	branch_country VARCHAR(20) CHECK(branch_country='JAPAN' or branch_country='Korea' or branch_country='China'),
);
CREATE TABLE Product
(
	id_product INT PRIMARY KEY IDENTITY,
	product_Name VARCHAR(100),
	pr_version VARCHAR(30),
	price FLOAT,
	id_category INT FOREIGN KEY REFERENCES ProductCategory(id_category),

);
CREATE TABLE ProductInventory
(
	
	id_productInventory INT FOREIGN KEY REFERENCES Product(id_product),
	quantity INT,
	created_at DATE,
	modified_at DATE,
	CONSTRAINT pk_ProductInventory PRIMARY KEY(id_productInventory)

);

CREATE TABLE ProductDescription
(
	normal_description VARCHAR(500),
	pre_order_benefits VARCHAR(500),
	id_productDescription INT FOREIGN KEY REFERENCES Product(id_product),
	CONSTRAINT pk_ProductDescription PRIMARY KEY(id_productDescription)

);

CREATE TABLE ProductInfo
(
	id_product_info INT FOREIGN KEY REFERENCES Product(id_product),
	barcode VARCHAR(30) NOT NULL,
	releaseDate DATE,
	id_group INT FOREIGN KEY REFERENCES Band(id_group),
	id_artist INT FOREIGN KEY REFERENCES Artist(id_artist),
	CONSTRAINT pk_ProductInfo PRIMARY KEY (id_product_info),
	CONSTRAINT chk_ProductInfoExclusiveOr CHECK (
        (id_group IS NULL AND id_artist IS NOT NULL) OR
        (id_group IS NOT NULL AND id_artist IS NULL)
    )
);

CREATE TABLE ClientOrder
(
	id_order INT PRIMARY KEY IDENTITY,
	id_client INT FOREIGN KEY REFERENCES Client(id_client),
	total_sum FLOAT,
	finalized_at DATE,
	id_address INT FOREIGN KEY REFERENCES PersonalAddress(id_address),
	mobilePhone VARCHAR(13)
);

CREATE TABLE OrderedProduct
(
	id_order INT FOREIGN KEY REFERENCES ClientOrder(id_order),
	id_product INT FOREIGN KEY REFERENCES Product(id_product),
	quantity INT,
	CONSTRAINT pk_OrderedProduct PRIMARY KEY (id_order,id_product)
);
CREATE TABLE Payment
(
	id_payment INT FOREIGN KEY REFERENCES ClientOrder(id_order),
	payment_type VARCHAR(100)  CHECK( payment_type='CASH' or payment_type='CARD') DEFAULT 'CASH',
	bank VARCHAR(100),
	CONSTRAINT pk_Payment PRIMARY KEY (id_payment)
);