create database partial_223
use partial_223
/*
	Canale-> id_canal,denumire,rating
	TipuriDeSeriale->id_tip,denumire,descriere
	Seriale->id_serial,denumire,prezentare,numar_de_sezoane,id_tip,id_canal
	Utilizatori->id_utilizator,nume,prenume,gen,varsta
	WatchingList->id_serial,id_utilizator,data_lansarii,ora_difuzarii
*/
---creare tabele
create table Canale
(
	id_canal int primary key identity,
	denumire varchar(100),
	rating int
);
create table TipuriDeSeriale
(
	id_tip int primary key identity,
	denumire varchar(100),
	descriere varchar(200)
);
create table Seriale
(
	id_serial int primary key identity,
	denumire varchar (100),
	prezentare varchar(200),
	numar_de_sezoane int,
	id_tip int  foreign key references TipuriDeSeriale(id_tip),
	id_canal int foreign key references Canale(id_canal)
);
create table Utilizatori
(
	id_user int primary key identity,
	nume varchar(100),
	prenume varchar(100),
	gen varchar(20),
	varsta int check(varsta >=0)
);

create table WatchingList
(
	id_serial int foreign key references Seriale(id_serial),
	id_utilizator int foreign key references Utilizatori(id_user),
	data_lansarii DATE,
	ora_difuzarii TIME,
	constraint pk_WatchingList primary key (id_serial,id_utilizator)

);

--inserting data into them


-- Insert data into the Canale table
INSERT INTO Canale (denumire, rating) VALUES
('Channel 1', 4),
('Channel 2', 5),
('Channel 3', 3);
select * from Canale
-- Insert data into the TipuriDeSeriale table
INSERT INTO TipuriDeSeriale (denumire, descriere) VALUES
('Comedy', 'Funny and entertaining series'),
('Drama', 'Emotional and intense series'),
('Action', 'Thrilling and action-packed series');

-- Insert data into the Seriale table
INSERT INTO Seriale (denumire, prezentare, numar_de_sezoane, id_tip, id_canal) VALUES
('Series 1', 'A captivating series about...', 3, 1, 1),
('Series 2', 'An intense drama series...', 5, 2, 2),
('Series 3', 'Action-packed series with...', 4, 3, 3);

-- Insert data into the Utilizatori table
INSERT INTO Utilizatori (nume, prenume, gen, varsta) VALUES
('John', 'Doe', 'Male', 25),
('Jane', 'Doe', 'Female', 30),
('Alex', 'Smith', 'Male', 22),
('Clara','Her','Female',20),
('Iulius','Mar','Male',10),
('Clark','Kent','Male',30);

--2
	--creating upsert procedure
create or alter procedure upsert_WatchingList 
(
	@id_serial int,
	@id_user int,
	@data_lansare DATE,
	@ora TIME
)
AS
BEGIN
	--first,verific daca exista deja in tabelul watching list -> update
	IF EXISTS(SELECT 1 from WatchingList where id_serial=@id_serial and id_utilizator=@id_user)
		BEGIN
			Print 'Updating WatchingList for User.';
			update WatchingList
				set data_lansarii=@data_lansare, ora_difuzarii=@ora
				where id_serial=@id_serial and id_utilizator=@id_user;
			Print 'WatchingList series for User was updated!';
			RETURN
		END
	--altfel inseamna ca nu exista
	--dar inainte verific daca serialul dat si userul exista in database
	--verificare id_utilizator
	DECLARE @ERRORS VARCHAR(200)='';
	IF NOT EXISTS(Select 1 from Utilizatori where id_user=@id_user)
		BEGIN
			SET @ERRORS ='User does not exist!...';
		END
	--verificare id_serial
	IF NOT EXISTS(Select 1 from Seriale where id_serial=@id_serial)
		BEGIN
			SET @ERRORS +='Series does not exist!...';
		END
	if @ERRORS<>''
		BEGIN
			print 'Errors found!...'
			raiserror(@ERRORS,16,1)
			return
		END
	
	--daca totul e in regula se ajunge aici unde inserez
	insert into WatchingList (id_serial,id_utilizator,data_lansarii,ora_difuzarii)
		values (@id_serial,@id_user,@data_lansare,@ora)
	print 'The series was inserted to the users watching List!'
END
GO
---3.View.
--inserting into Watching List
--inserare gresita
exec upsert_WatchingList 10,10,'2023-12-1','7:00';
exec upsert_WatchingList 1,1,'2023-09-09','21:00';
exec upsert_WatchingList 1,2,'2023-09-09','21:00';
exec upsert_WatchingList 1,3,'2023-09-09','21:00';
exec upsert_WatchingList 2,1,'2023-09-09','21:00';
exec upsert_WatchingList 2,2,'2023-09-09','21:00';
exec upsert_WatchingList 2,3,'2023-09-09','21:00';
exec upsert_WatchingList 2,4,'2023-09-09','21:00';
exec upsert_WatchingList 3,1,'2023-09-08','21:00';
select * from WatchingList
create view View_SerialeCuCelPutin3Utilizatori
as
	select
	s.denumire as Serial,
	count(w.id_utilizator) as NumarUtilizatori
	from WatchingList as w
	inner join Seriale as s on s.id_serial=w.id_serial
	group by w.id_serial,s.denumire
	having count(w.id_serial)>=3
select * from View_SerialeCuCelPutin3Utilizatori
-- Insert data into the WatchingList table
