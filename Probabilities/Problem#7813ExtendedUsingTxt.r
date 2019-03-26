
setwd("C:/Users/Dosya/Desktop/Programming/Education/Probabilities")
getwd()
df <- readWorksheetFromFile("data.xls", 
                            sheet=3, 
                            startRow = 10,
                            endRow = 12
                            
)

vec <- as.character(df[1,])
vec <- gsub(",", ".", vec)
vec <- gsub(" ", "", vec)

print(df)
