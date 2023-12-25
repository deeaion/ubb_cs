----modifica tipul unei coloane la client
Use KpopStore;
CREATE TABLE VersionTable
(	nr_versiune INT DEFAULT 0 NOT NULL
);
-----change last name type to nvarchar to be able to use diacritice
CREATE PROCEDURE ChangeLastName_ToNVarChar
AS
BEGIN

	ALTER TABLE PersonalInformation
	ALTER COLUMN last_name NVARCHAR(100) NOT NULL
END
-------change last name back to varchar
CREATE PROCEDURE ChangeLastName_BackToVarchar
AS
BEGIN
	ALTER TABLE PersonalInformation
	ALTER COLUMN last_name VARCHAR(100) NOT NULL
END




--------add default constraint. when there is an order product if not entered the default
--------value of it is 1 
CREATE PROCEDURE AddDefaultValueToQuantity
AS
BEGIN
	ALTER TABLE OrderedProduct
	ADD CONSTRAINT df_NumberOfProducts DEFAULT 1 for quantity 
END
--------retract default constraint for ordered product
CREATE PROCEDURE RemoveDefaultValueToQuantity
AS
BEGIN
	ALTER TABLE OrderedProduct
	DROP CONSTRAINT df_NumberOfProducts
END

----add a new table. A table of Subscription. 

CREATE PROCEDURE AddSubscriptionTable
AS
BEGIN
	CREATE TABLE Subscription
	(
		id_subscription INT NOT NULL PRIMARY KEY,
		type VARCHAR(20) NOT NULL,
		date_it_started DATE,
	);
END

-------delete added subscription table
CREATE PROCEDURE DeleteSubscription
AS
BEGIN
	DROP TABLE Subscription
END

---add new column to subscription table
CREATE PROCEDURE AddSubscriptionDiscount
AS
BEGIN
	ALTER TABLE Subscription
	ADD discount_percentage FLOAT
END
--remove column discound of subscription table
CREATE or alter PROCEDURE RemoveSubscriptiionDiscount
AS
BEGIN
	ALTER TABLE Subscription
	DROP COLUMN discount_percentage
END
select * from subscription


-- add constraint to foreign key
CREATE PROCEDURE LinkSubscriptionToClient
AS
BEGIN
	ALTER TABLE Subscription
	ADD CONSTRAINT FK_ID_SUBSCRIPTION
	FOREIGN KEY (id_subscription) references client(id_client)
END
exec LinkSubscriptionToClient
--remove constrain of table

CREATE PROCEDURE RemoveConstraintSubscription
AS
BEGIN
	ALTER TABLE Subscription
	DROP CONSTRAINT FK_ID_SUBSCRIPTION
END

INSERT INTO VersionTable VALUES (0);

CREATE TABLE DirectProcedures
(
	id_dirProd INT PRIMARY KEY,
	nume_procedura varchar(200)

);
drop table directprocedures
CREATE TABLE ReverseProcedures
(
	id_dirProd INT PRIMARY KEY,
	nume_procedura varchar(200)

);


INSERT INTO directprocedures 
VALUES 
(1,'ChangeLastName_ToNVarChar'),
(2,'AddDefaultValueToQuantity'),
(3,'AddSubscriptionTable'),
(4,'AddSubscriptionDiscount'),
(5,'LinkSubscriptionToClient');
SELECT * from directprocedures;
INSERT INTO ReverseProcedures
VALUES
(1,'ChangeLastName_BackToVarchar'),
(2,'RemoveDefaultValueToQuantity'),
(3,'DeleteSubscription'),
(4,'RemoveSubscriptiionDiscount'),
(5,'RemoveConstraintSubscription')

CREATE OR ALTER PROCEDURE main
@VersiunePrim FLOAT

AS
BEGIN
	IF FLOOR (@VersiunePrim) <> CEILING(@VersiunePrim)
		BEGIN
		raiserror('Numarul trebuie sa fie un integer!',16,1);
		RETURN;
		END
	DECLARE @Versiune AS INT
	SET @Versiune=FLOOR(@VersiunePrim)
	IF @Versiune>5
		BEGIN
			raiserror('Versiunea nu poate ajunge la stagiul acela!',16,1);
			RETURN;
		END
	IF @Versiune<0
		BEGIN
			raiserror('Versiunea nu poate fi un numar negativ!',16,1);
		END
	DECLARE @Versiune_actuala AS INT
	SELECT @Versiune_actuala=nr_versiune from VersionTable;
	Print 'Versiunea actuala este :';
	Print @Versiune_actuala;
	Print 'Versiunea ceruta este: ';
	Print @Versiune;



	DECLARE @Functie AS varchar(100);


	if @Versiune=@Versiune_actuala
		BEGIN
			print 'Suntem deja in versiunea aceasta';
			return;
		
		END


	 if @Versiune>@Versiune_actuala
		BEGIN
			while @Versiune_actuala!=@Versiune
				BEGIN
					SELECT @Functie= nume_procedura from directprocedures where id_dirProd=@Versiune_actuala+1;
					EXEC  @Functie;

					SET @Versiune_actuala=@Versiune_actuala+1;
				END
			UPDATE VersionTable
			Set nr_versiune=@Versiune
		END
	else if @Versiune<@Versiune_actuala
		BEGIN
			while @Versiune_actuala!=@Versiune
				BEGIN
					SELECT @Functie= nume_procedura from ReverseProcedures where id_dirProd=@Versiune_actuala;
					EXEC  @Functie;

					SET @Versiune_actuala=@Versiune_actuala-1;
				END
			UPDATE VersionTable
			Set nr_versiune=@Versiune;
			RETURN
		END

END;
drop main;
select * from PersonalInformation
ExEc main 4.5;
select * from VersionTable

select * from subscription;
insert into subscription values(1,'gold','2023-11-11',20)
UPDATE VersionTable
SET nr_versiune=3
exec DeleteSubscription
select * from DirectProcedures
select * from ReverseProcedures