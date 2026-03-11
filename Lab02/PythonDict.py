thisdict = [
{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
},
{
  "brand": "Mazda",
  "model": "626",
  "year": 2000
},
{
  "brand": "Mercedes",
  "model": "AMG",
  "year": 2016
}]
print(thisdict)

#insertion sort
n=len(thisdict) #n = the length of the array
i = 1

while i < n:
    j = i
    
    while j > 0 and thisdict[j-1]["year"] < thisdict[j]["year"]: #< is desc, > is ascend
        thisdict[j], thisdict[j-1] = thisdict[j-1], thisdict[j]   # swap
        j = j - 1
    
    i = i + 1

print (thisdict)