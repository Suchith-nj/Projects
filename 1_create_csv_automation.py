import csv


filename = "file.csv"
r = []
with open(filename, 'w') as csvfile:
    writer = csv.writer(csvfile)

    s = open("stats.txt", 'r')

    for x in s:
        if 'txt' in x:
            writer.writerow(r)
            print(r)
            r = []
            r.append(x)
            item  = x.split('.')
            item  = item[0].split('_') 
            r.extend(item)
        elif "system.cpu.dcache.overall_miss_rate::total" in x or "system.cpu.icache.overall_miss_rate::total" in x or "system.l2.overall_miss_rate::total" in x or "system.cpu.dcache.overall_accesses::total" in x or "system.cpu.icache.overall_accesses::total" in x or "system.l2.overall_accesses::total" in x: 
            for t in x.split():
                try:
                    r.append(float(t))
                except ValueError:
                    pass
        else:
            pass