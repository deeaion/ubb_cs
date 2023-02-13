#FUNCTIONSSS


from datetime import date
today=date.today()
#Test if leap year
def test_leap_day(year):
    if year%4==0:
        if(year%100==0 and year%400!=0):
            return False
        return True
    return False

#Test the number of days of the month
def type_of_month(month,year):
    if month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12:
        return 31
    if month==4 or month==6 or month==9 or month==11:
        return 30
    if month==2:
        if test_leap_day(year)==True:
            return 29
        else:
            return 28
        
#Test the number of days for the years when the birth happens/ the current date
def the_left_days_bday(day,month,year):
    nr=0
    for i in range(month,12+1,1):
     if i==month:
            nr=nr+type_of_month(month,year)-day+1
     else:
        nr+=type_of_month(month,year)
    return nr
def before_today(day,month,year):
    nr=0
    for i in range(1,month+1):
        if(i==month):
            nr=nr+day
        else:
            nr+=type_of_month(i,year)
    return nr

number_of_days=0

#User-input:

birth_day=int(input("Day of birth:"))
birth_month=int(input("Month of birth(in numbers):"))
birth_year=int(input("Year of Birth:"))

#Calculezi nr de zile fara anul nasterii si cel curent
for i in range(birth_year+1,today.year):
    if(test_leap_day(i)==True):
        number_of_days=number_of_days+366
    else:
        number_of_days+=365
    birth_year+=1
    
#Adaugi zilele din anul de nastere
number_of_days+=the_left_days_bday(birth_day,birth_month,birth_year)
number_of_days+=before_today(today.day,today.month,today.year)

print("The number of days lived by the inserted person is: " + str(number_of_days))


    
