#FUNCTIONS
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
#User-input:
nr_ordine=int(input("Dati numarul de ordine:"))
year=int(input("Dati anul:"))
i=1
nr_days_tested=0
while(i<=12 and nr_days_tested<=nr_ordine):
    nr_days_tested+=type_of_month(i,year)
    i+=1
if nr_days_tested==nr_ordine:
    month=i-1
    day=type_of_month(i-1,year)
if nr_days_tested>nr_ordine:
    month=i-1
    day=type_of_month(i-1,year)-(nr_days_tested-nr_ordine)
print("Data zilei de oridine",nr_ordine,"este:",year,"/",month,"/",day)
