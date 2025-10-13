import csv

def procesare_csv(file_static,file_dynamic, output_file='comparatie_static_vs_dinamic.csv'):
    # Citesc fisierele csv
    with open(file_static, 'r') as f:
        reader = csv.reader(f)
        data_static = list(reader)
    with open(file_dynamic, 'r') as f:
        reader = csv.reader(f)
        data_dynamic = list(reader)
    
    # Dictionarul cu cheie si valori
    #cheie -> (File, NumberOfThreads, PartitionType)
    #valoare -> (StaticTime, DynamicTime)
    comparatii = {}
    
    # pentru fiecare linie din fisierul static
    for i in range(1, len(data_static)):
        try:
            static_time = float(data_static[i][3].strip())  # Static time
        except ValueError:
            # it means it is empty -> Stack OverFlow
            static_time = 'Stack OverFlow'
            continue
        key=(data_static[i][0].strip(), int(data_static[i][2].strip()), data_static[i][4].strip())
        value=(static_time, 'N/A')
        comparatii[key] = value
    
    # pentru fiecare linie din fisierul dynamic
    for i in range(1, len(data_dynamic)):
        try:
            dynamic_time = float(data_dynamic[i][3].strip())  # Dynamic time
        except ValueError:
            # it means it is empty -> Stack OverFlow
            dynamic_time = 'Stack OverFlow'
            continue
        # caut cheia in dictionar
        key=(data_dynamic[i][0].strip(), int(data_dynamic[i][2].strip()), data_dynamic[i][4].strip())
        if key in comparatii:
            comparatii[key] = (comparatii[key][0], dynamic_time)
        else:
            comparatii[key] = ('N/A', dynamic_time)
        
    
    # Scriu in alt fisier csv
    with open(output_file, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['File', 'NumberOfThreads', 'PartitionType', 'StaticTime', 'DynamicTime', 'Difference'])
        
        for key, (static_time, dynamic_time) in comparatii.items():
            # Handle 'Stack OverFlow' or 'N/A' case for static time
            if static_time == 'Stack OverFlow':
                difference = 'Stack OverFlow In C'
            elif static_time == 'N/A':
                difference = 'N/A'
            else:
                # Ensure static_time is safely converted to float
                try:
                    difference = float(static_time) - float(dynamic_time)
                except ValueError:
                    difference = 'N/A'
            writer.writerow([key[0], key[1], key[2], static_time, dynamic_time, difference])
        
def procesare_csv_java_vs_c(fileJ, output_file='comparatie_java_vs_c.csv'):
    # Citesc fisierele csv
    
    # Citesc fisierele Java si comparatie_static_vs_dinamic.csv
    with open(fileJ, 'r') as f:
        reader = csv.reader(f)
        dataJ = list(reader)
    with open('comparatie_static_vs_dinamic.csv', 'r') as f:
        reader = csv.reader(f)
        dataC = list(reader)
    
    # Dictionarul cu cheie si valori
    comparatii = {}
    
    # pentru fiecare linie din fisierul java
    for i in range(1, len(dataJ)):
        try:
            java_time = float(dataJ[i][3].strip())  # Java time
        except ValueError:
            # Skip if java time is invalid
            continue
        comparatii[(dataJ[i][1].strip(), dataJ[i][2].strip(), dataJ[i][0].strip())] = (java_time, 'N/A', 'N/A')
    
    # pentru fiecare linie din fisierul C
    for i in range(1, len(dataC)):
        try:
            c_time = float(dataC[i][3].strip())  # C static time
        except ValueError:
            c_time = 'N/A'
        try:
            d_time = float(dataC[i][4].strip())  # C dynamic time
        except ValueError:
            d_time = 'N/A'
        fileName=dataC[i][0].strip()
        threadNumber=dataC[i][1].strip()
        partitionType=dataC[i][2].strip()
        key=(fileName, threadNumber, partitionType)
        if key in comparatii:
            comparatii[key] = (comparatii[key][0], c_time, d_time)
        else:
            comparatii[key] = ('N/A', c_time, d_time)
    
    # Scriu in alt fisier csv
    with open(output_file, 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['File', 'NumberOfThreads', 'PartitionType', 'JavaTime', 'CStaticTime', 'CDynamicTime', 'DifferenceStatic', 'DifferenceDynamic'])
        
        for key, (java_time, static_time, dynamic_time) in comparatii.items():
            # Handle 'Stack OverFlow' or 'N/A' case for static time
            if static_time == 'Stack OverFlow':
                difference_static = 'Stack OverFlow In C'
            elif static_time == 'N/A':
                difference_static = 'N/A'
            else:
                # Ensure static_time is safely converted to float
                try:
                    difference_static = float(static_time) - float(java_time)
                except ValueError:
                    difference_static = 'N/A'

            # Format Java time and C times
            try:
                java_time_formatted = f'{float(java_time):.4f}'
            except ValueError:
                java_time_formatted = 'N/A'
            
            if static_time != 'N/A':
                static_time_formatted = f'{float(static_time):.4f}'
            else:
                static_time_formatted = 'N/A'
            
            if dynamic_time != 'N/A':
                dynamic_time_formatted = f'{float(dynamic_time):.4f}'
                difference_dynamic = float(dynamic_time) - float(java_time)
                difference_dynamic_formatted = f'{difference_dynamic:.4f}'
            else:
                dynamic_time_formatted = 'N/A'
                difference_dynamic_formatted = 'N/A'
            
            writer.writerow([key[0], key[1], key[2], java_time_formatted, static_time_formatted, dynamic_time_formatted, difference_static, difference_dynamic_formatted])

    print(f"Comparatia a fost scrisa in fisierul {output_file}.")

# procesare_csv('outCStatic.csv', 'outCDynamic.csv')
procesare_csv_java_vs_c('outJ.csv', 'comparatie_java_vs_c.csv')