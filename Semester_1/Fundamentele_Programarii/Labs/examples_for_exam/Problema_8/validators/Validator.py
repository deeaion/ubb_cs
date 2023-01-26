from errors.ValidError import ValidError


class ValidatorEvent():
    def __init__(self):
        pass
    def validating(self,event):
        errors=""
        #date: dd.mm.yyyy
        date=event.get_date_event()
        if (len(date)!=10 and date[2]!="." and date[5]!="."):
            errors+="\nInvalid Date!"
        else:
            for l in range (len(date)):
                if (date[l]<'0' or date[l]>'9'):
                    if(date[l]!="."):
                        errors+="\n Invalid Date"
            day=int(date[:2])
            month=int(date[3:5])
            year=int(date[6:])
            if year<0:
                errors+="\n Invalid Date"
            if month<0 or month>12:
                errors+="\n Invalid Date"
            if (month>=1 or month <=7) and month%2==1:
                if day<0 or day>31:
                    errors+="\n Invalid Date"
            if (month>=1 or month <=7) and month%2==0 and month!=2:
                if day<0 or day>30:
                    errors+="\n Invalid Date"
            if (month==2):
                if day<0 or day>28:
                    errors+="\n Invalid Date"
            if month==8 or month==10 or month==12:
                if day<0 or day>31:
                    errors+="\n Invalid Date"
            if month==9 or month==11:
                if day<0 or day>30:
                    errors+="\n Invalid Date"

        #time hh:hh
        time=event.get_hour_event()
        if(len(time)!=5 and time[2]!=":"):
            errors+="\nInvalid Hour"
        else:
            hour=int(time[:2])
            if hour<0 or hour>24:
                errors += "\nInvalid Hour"
            else:
                minutes=int(time[3:])
                if minutes<0 or minutes>59:
                    errors += "\nInvalid Hour"
        if (len(event.get_description_event())==0):
            errors+="\nInvalid Description"
        if(len(errors)!=0):
            raise ValidError(errors)



