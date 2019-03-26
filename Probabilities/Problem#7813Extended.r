
setwd("C:/Users/Dosya/Desktop/Programming/Education/Probabilities")
getwd()


convertToDoubleList <-function(volume)
{
  volume<- c(volume[0:12],volume[18:27])
  volume <- gsub(",", ".", volume)
  volume <- gsub(" ", "", volume)
  
  volume <- as.numeric(volume)
}



df <- readWorksheetFromFile("data.xls", 
                            sheet=3, 
                            startRow = c(11,37,9),
                            endRow = c(12,38,10),
                            startCol = c(10,10,10),
                            endCol = c(36,36,36)
                            )


volumeMining <- as.character(df[[1]])
volumeMining <- convertToDoubleList(volumeMining)

volumeWaterSupply <- as.character(df[[2]])
volumeWaterSupply <- convertToDoubleList(volumeWaterSupply)

volumeTotal <- as.character(df[[3]])
volumeTotal <- convertToDoubleList(volumeTotal)



