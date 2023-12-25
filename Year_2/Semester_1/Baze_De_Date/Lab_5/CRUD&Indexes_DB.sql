----I DO NOT ALLOW Empty strings to be inserted-----
---VALIDATING---
--SIMPLE VALIDATIONS--
create or alter function Validate_Parameter_Is_Not_Null(@sir VARCHAR(100))
	RETURNS INT
AS
BEGIN
	IF @sir IS NOT NULL 
	BEGIN
		IF @sir =''
		BEGIN
			RETURN 0
		END
		RETURN 1
	END
	RETURN 0
END
GO
SELECT dbo.Validate_Parameter_Is_Not_Null('');

----VALIDATING TypeOfGroup since I am allowing the user to specify the id-----
create function Validate_Type_Of_Group(@id INT)
	RETURNS INT
AS
BEGIN
	--daca exista un rez din select -> exista tipul altfel nu--
	IF EXISTS(SELECT * from TypeOfGroup WHERE id_type=@id) 
	BEGIN
		RETURN 1
	END
	RETURN 0
END
GO


----check if Artist exists in DB------
create function Validate_ArtistId(@id INT)
	RETURNS INT
AS
BEGIN
	IF EXISTS(SELECT * from Artist WHERE id_artist=@id)
	BEGIN
		RETURN 1
	END
	RETURN 0
END
GO

--check if band exist in DB------
create function Validate_BandId(@id INT)
	RETURNS INT
AS
BEGIN
	IF EXISTS(SELECT * from Band WHERE id_group=@id)
	BEGIN
		RETURN 1
	END
	RETURN 0
END
GO


---VALIDATING IF i can add the member-group link. If they are already registered in that group then I cannot add it---
create function Validate_MemberGroup(@id_artist INT,@id_group INT)
	RETURNS INT
AS
BEGIN
	IF EXISTS(SELECT * FROM GroupMembersInfo WHERE GroupMembersInfo.id_artist=@id_artist and GroupMembersInfo.id_group=@id_group)
	BEGIN
		RETURN 0
	END
	RETURN 1
END
GO

create function Validate_IsIntNonNegative(@supposed_integer FLOAT)
	RETURNS INT
AS
BEGIN
	IF FLOOR (@supposed_integer) <> CEILING(@supposed_integer)
		BEGIN
			RETURN -1 --returnez -1 cand e float--
		END
	IF @supposed_integer<0
		BEGIN
			RETURN -2
		END
	RETURN FLOOR(@supposed_integer)--daca totul e in regula returnez int ul 
END


--validate group members info---
CREATE OR ALTER PROCEDURE Validate_GroupMembersInfo
(
    @id_artistF FLOAT,
    @id_groupF FLOAT,
    @id_artist INT OUTPUT,
    @id_group INT OUTPUT
)
AS
BEGIN
    -- Declare a variable to accumulate error messages
    DECLARE @ErrorMessages NVARCHAR(MAX) = '';

    -- Validating id artist
    SET @id_artist = dbo.Validate_IsIntNonNegative(@id_artistF);
    IF @id_artist = -1
    BEGIN
        SET @ErrorMessages += 'Artist Id must be int! You introduced a float!'+ CHAR(13) + CHAR(10);
    END
    IF @id_artist = -2
    BEGIN
        SET @ErrorMessages += 'Artist Id must be not negative! You introduced a negative number!'+ CHAR(13) + CHAR(10);
    END
	IF dbo.Validate_ArtistId(@id_artist)=0
	BEGIN
		SET @ErrorMessages += 'Artist with ID does not exist'+ CHAR(13) + CHAR(10);
	END
    -- Validating id band
    SET @id_group = dbo.Validate_IsIntNonNegative(@id_groupF);
    IF @id_group = -1
    BEGIN
        SET @ErrorMessages += 'Group Id must be int! You introduced a float!'+ CHAR(13) + CHAR(10);
    END
    IF @id_group = -2
    BEGIN
        SET @ErrorMessages += 'Group Id must be not negative! You introduced a negative number!'+ CHAR(13) + CHAR(10);
    END
	IF dbo.Validate_BandId(@id_group)=0
	BEGIN
		SET @ErrorMessages+='Group ID does not exist in DB'+ CHAR(13) + CHAR(10);
	END

    -- Validating entry
    IF dbo.Validate_MemberGroup(@id_artist, @id_group) = 0
    BEGIN
        SET @ErrorMessages += 'Combination Already Exists!'+ CHAR(13) + CHAR(10);
    END

    -- Display accumulated error messages
    IF @ErrorMessages <> ''
    BEGIN
        RAISERROR(@ErrorMessages, 16, 1);
        RETURN 0;
    END

    -- No errors, return success code or other value if needed
    RETURN 1;
END;



----validate artist----
create procedure Validate_Artist(
								@first_name VARCHAR(100),
								@second_name VARCHAR(100),
								@stage_name VARCHAR (100)
								)

AS
BEGIN
    -- Declare a variable to accumulate error messages
    DECLARE @ErrorMessages NVARCHAR(MAX) = '';

    -- Validating id artist
    IF dbo.Validate_Parameter_Is_Not_Null(@first_name)= 0
    BEGIN
        SET @ErrorMessages += 'First Name must not be null!\n';
    END
    IF dbo.Validate_Parameter_Is_Not_Null(@second_name)= 0
    BEGIN
        SET @ErrorMessages += 'Second Name must not be null!\n';
    END
	 IF dbo.Validate_Parameter_Is_Not_Null(@stage_name)= 0
    BEGIN
        SET @ErrorMessages += 'Stage name must not be null!\n';
    END
    -- Display accumulated error messages
    IF @ErrorMessages <> ''
    BEGIN
        RAISERROR(@ErrorMessages, 16, 1);
        RETURN 0;
    END

    -- No errors, return success code or other value if needed
    RETURN 1;
END




----validate band---
create procedure Validate_Band(
								@group_name VARCHAR(200),
								@debut_dateV VARCHAR(30),
								@records_numberF FLOAT,
								@id_typeofGroupF FLOAT,
								@debut_date DATE OUTPUT,
								@records_number INT OUTPUT,
								@id_typeofGroup INT OUTPUT
								)

AS
BEGIN
    -- Declare a variable to accumulate error messages
    DECLARE @ErrorMessages NVARCHAR(MAX) = '';

    -- Validating id artist
    IF dbo.Validate_Parameter_Is_Not_Null(@group_name)= 0
    BEGIN
        SET @ErrorMessages += 'Group Name must not be null!\n';
    END



    SET @records_number=dbo.Validate_Parameter_Is_Not_Null(@records_numberF);
	 IF @records_number = -1
    BEGIN
        SET @ErrorMessages += 'Records Number must be int! You introduced a float!\n';
    END
    IF @records_number = -2
    BEGIN
        SET @ErrorMessages += 'Records Number must be not negative! You introduced a negative number!\n';
    END



	SET @id_typeofGroup=dbo.Validate_Parameter_Is_Not_Null(@id_typeofGroupF);
	IF @id_typeofGroup = -1
    BEGIN
        SET @ErrorMessages += 'Id of Group must be int! You introduced a float!\n';
    END
    IF @id_typeofGroup = -2
    BEGIN
        SET @ErrorMessages += 'Id of Group must be not negative! You introduced a negative number!\n';
    END
	IF @id_typeofGroup !=-1 and @id_typeofGroup!=-2
		and dbo.Validate_Type_Of_Group(@id_typeofGroup)=0
	BEGIN
		SET @ErrorMessages+='Type with that ID does not exist in the DB!\n'
	END
	-- Validating and converting debut date
    SET @debut_date = TRY_CONVERT(DATE, @debut_dateV);
    IF @debut_date IS NULL
    BEGIN
        SET @ErrorMessages += 'Invalid Debut Date format or null!\n';
    END

    -- Display accumulated error messages
    IF @ErrorMessages <> ''
    BEGIN
        RAISERROR(@ErrorMessages, 16, 1);
        RETURN 0;
    END

    -- No errors, return success code or other value if needed
    RETURN 1;
END













----------------CRUD----------------------------


----------CRUD ARTIST------------------------
CREATE OR ALTER PROCEDURE CRUD_Artist
	@first_name VARCHAR(100),
	@second_name VARCHAR(100),
	@stage_name VARCHAR (100),
	@NoOfRows INT

AS
BEGIN
	SET NOCOUNT ON;
	--validate
	BEGIN TRY
	exec dbo.Validate_Artist @first_name,@second_name,@stage_name;

	--insert
	DECLARE @n INT=0;
	WHILE @n<@NoOfRows
		BEGIN
			INSERT INTO Artist values (@first_name,@second_name,@stage_name);
			SET @n=@n+1;
		END
	--select
	select * from Artist
	ORDER by Artist.stage_name
	--update
	UPDATE Artist
		SET Artist.stage_name=@stage_name+'_CRUD'
	WHERE Artist.stage_name=@stage_name;
	--select
	select * from Artist order by Artist.stage_name;
	--delete
	delete from Artist
	WHERE Artist.stage_name LIKE @stage_name+'_CRUD';
	--select
	select * from Artist order by Artist.stage_name;
	--gata
	PRINT 'CRUD operations were done successfully'
	END TRY
    BEGIN CATCH
        -- Handle the error
        PRINT 'An error occurred: ' + ERROR_MESSAGE();
    END CATCH

END
exec CRUD_Artist 'Ana','Are','AnaAre',4
select * from TypeOfGroup

----------CRUD GROUP------------------------
CREATE OR ALTER PROCEDURE CRUD_Group
	@group_name VARCHAR(200),
	@debut_dateV VARCHAR(100),
	@records_numberF FLOAT,
	@id_typeOfGroupF FLOAT,
	@NoOfRows INT

AS
BEGIN
	SET NOCOUNT ON;
	--validate
	DECLARE @debut_date DATE,@records_number INT,@id_typeOfGroup INT;
	BEGIN TRY
	exec dbo.Validate_Band @group_name,
								@debut_dateV,
								@records_numberF,
								@id_typeofGroupF,
								@debut_date OUTPUT,
								@records_number OUTPUT,
								@id_typeofGroup OUTPUT;
	--insert
	DECLARE @n INT=0;
	WHILE @n<@NoOfRows
		BEGIN
			INSERT INTO Band values (@group_name,@debut_date,@records_number,@id_typeOfGroup);
			SET @n=@n+1;
		END
	--select
	select * from Band
	ORDER by Band.group_name DESC
	--update
	UPDATE Band
		SET Band.group_name=@group_name+'_CRUD'
	WHERE Band.group_name=@group_name;
	--select
	select * from Band
	ORDER by Band.group_name DESC
	--delete
	delete from Band
	WHERE Band.group_name LIKE @group_name+'_CRUD';
	--select
	select * from Band
	ORDER by Band.group_name DESC
	--gata
	PRINT 'CRUD operations were done successfully'
	 END TRY
    BEGIN CATCH
        -- Handle the error
        PRINT 'An error occurred: ' + ERROR_MESSAGE();
    END CATCH

END
EXEC CRUD_Group 'SKZ','2022-12',2,1,5


----------CRUD GroupMembersInfo------------------------
CREATE OR ALTER PROCEDURE CRUD_GroupMembersInfo
	@id_artistF FLOAT,
	@id_groupF FLOAT,
	@position VARCHAR(100)

AS
BEGIN
	SET NOCOUNT ON;
	--validate
	DECLARE @id_artist INT,@id_group INT;
	BEGIN TRY
	exec dbo.Validate_GroupMembersInfo  @id_artistF,
										 @id_groupF,
										 @id_artist OUTPUT,
										 @id_group OUTPUT
	--insert
	INSERT INTO GroupMembersInfo VALUES (@id_artist,@id_group,@position);
	--select
	select * from GroupMembersInfo
	ORDER by GroupMembersInfo.position DESC
	--update
	UPDATE GroupMembersInfo
		SET position=@position+'_CRUD'
	WHERE GroupMembersInfo.id_artist=@id_artist and GroupMembersInfo.id_group=@id_group;
	--select
	select * from GroupMembersInfo
	ORDER by GroupMembersInfo.position DESC
	--delete
	delete from GroupMembersInfo
	WHERE GroupMembersInfo.position LIKE @position+'_CRUD';
	--select
	select * from GroupMembersInfo
	ORDER by GroupMembersInfo.position DESC
	--gata
	PRINT 'CRUD operations were done successfully'
	END TRY
	 BEGIN CATCH
        -- Handle the error
        PRINT 'An error occurred: ' + ERROR_MESSAGE();
    END CATCH

END
delete from GroupMembersInfo where id_artist=2 and id_group=3
EXEC CRUD_GroupMembersInfo 2, 3,'rapper'
EXEC CRUD_GroupMembersInfo 100, 3,'rapper'
EXEC CRUD_Artist '','I','s',100
EXEC CRUD_Artist 'Hello','I','s',100
select * from GroupMembersInfo




select * from Artist
-----------VIEWS--------------------

CREATE OR ALTER VIEW View_Artists AS
	SELECT first_name,last_name,stage_name from Artist
	WHERE stage_name like 'J%'or stage_name like 'a%'

GO

select * from band
CREATE OR ALTER VIEW View_Band AS
	SELECT group_name,records_number from Band
	WHERE group_name LIKE 'NCT%'
GO
select * from GroupMembersInfo

CREATE or alter VIEW View_RappersGroups AS

	SELECT
		a.stage_name,
		b.group_name,
		g.position
		FROM GroupMembersInfo g
		INNER JOIN Band b ON g.id_group=b.id_group and b.group_name LIKE 'NCT%'
		INNER JOIN Artist a ON g.id_artist=a.id_artist
		WHERE g.position='rapper';

SELECT * from View_RappersGroups

SELECT * from View_Artists
select * from View_Band
SELECT * from View_RappersGroups


IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_group_position')
DROP INDEX N_idx_group_position ON GroupMembersInfo
CREATE NONCLUSTERED INDEX N_idx_group_position ON GroupMembersInfo(position);


IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_group_pack')
DROP INDEX N_idx_group_pack ON GroupMembersInfo
CREATE NONCLUSTERED INDEX N_idx_group_pack ON GroupMembersInfo(id_artist,id_group,position);


IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_band_groupnameID')
DROP INDEX N_idx_band_groupnameID ON Band
CREATE NONCLUSTERED INDEX N_idx_band_groupnameID ON Band(id_group,group_name)



IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_artist_stagename')
DROP INDEX N_idx_artist_stagename ON Artist
CREATE NONCLUSTERED INDEX N_idx_artist_stagename ON Artist(stage_name)
IF EXISTS (SELECT NAME FROM sys.indexes WHERE name='N_idx_band_groupname')
DROP INDEX N_idx_band_groupname ON Band
CREATE NONCLUSTERED INDEX N_idx_band_groupname ON Band(group_name)

