
setwd("C:/Users/Dosya/Desktop/Programming/Education/Probabilities")
getwd()


convertToDoubleList <-function(volume)
{
  volume<- c(volume[0:12],volume[18:27])
  volume <- gsub(",", ".", volume)
  volume <- gsub(" ", "", volume)
  
  volume <- as.numeric(volume)
}

# Assigment 1

df <- readWorksheetFromFile("data.xls", 
                            sheet=3, 
                            startRow = c(11,37,17,32,9),
                            endRow = c(12,38,18,33,10),
                            startCol = c(10,10,10,10,10),
                            endCol = c(36,36,36,36,36)
                            )


volumeMining <- as.character(df[[1]])
volumeMining <- convertToDoubleList(volumeMining)

volumeWaterSupply <- as.character(df[[2]])
volumeWaterSupply <- convertToDoubleList(volumeWaterSupply)

volumeTotal <- as.character(df[[5]])
volumeTotal <- convertToDoubleList(volumeTotal)

volumeDifference <- volumeMining - volumeWaterSupply

volumeWithRespectTotal <- (volumeDifference / volumeTotal) * 100

shapiro.test(volumeWithRespectTotal)

t.test(volumeWithRespectTotal,conf.level=0.9)
# Answer CI = [2.527357, 3.437553]


# Assigment 2
volumeEnergy <- as.character(df[[4]])
volumeEnergy <-convertToDoubleList(volumeEnergy)
volumeManuf <- as.character(df[[3]])
volumeManuf <-convertToDoubleList(volumeManuf)

volumeSum <-  volumeEnergy + volumeManuf

#partialTotal 292604 < volume sum 293400
partialTotalVolume <- volumeSum / volumeTotal * 100  

shapiro.test(partialTotalVolume)
# p-value = 0.8991 reject Normal Distribution
t.test(partialTotalVolume, alternative ="greater",mu=95)
