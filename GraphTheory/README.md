## Gale Shapely Algorithm
    - Demonstrate finding a stable equal sized set of matches between all elements in A and B sets

## Usage
    - Medical Residency matching
    - University admissions
    - Dating App
    - Many more

## An example of how it works 
    - Assume all the elements in the data set from A and B are not yet paired to each other 
    - Iterate either from set A or B who is not yet paired to any one from inverse choice in the iteration
        - Either from set A or B paired to the highest ranked the set A or B haven't paired yet
        - if Set A or B is not yet paired -> paired them together
        - if set A or B is paired -> compare two elements(old vs new) in the inverse chosen set 
            - if set A or B prefer the new element -> swap the old elemenet to the new one and the old element is not paired again
            - if set A or B prefer the old one element -> disregard the change

     - REPEAT until every elements in Set A and B are paired together 




