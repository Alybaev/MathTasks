
# Init
getwd()
library(XLConnect)

months <- seq(as.Date("01/01/17", format = "%d/%m/%y"), by = "month", length = 22)

constructTheVolumePlot <-function(xData,name)
{
  
  plot(months, xData, main = name,type="b", col="red", pch=c(15,19),xlab = "Date",
       las=1,ylab = "Volume",xaxt = "n")
  
  axis(side = 1, at = months, labels = months)
}

constructTheSharePlot <-function(xData,name)
{
  
  plot(months, xData, main = name,type="b", col="blue", pch=c(15,19),
       xlab = "Date",ylab = "Share of Volume production, %", 
       las=1,xaxt = "n")
  
  axis(side = 1, at = months, labels = months)
  
}

convertToDoubleList <-function(volume)
{
  
  volume<- c(volume[0:12],volume[18:27])
  volume <- gsub(",", ".", volume)
  volume <- gsub(" ", "", volume)
  
  volume <- as.numeric(volume)
  
}

df <- readWorksheetFromFile("data.xls", 
                            sheet=3, 
                            startRow = c(11,37,17,32,9),
                            endRow = c(12,38,18,33,10),
                            startCol = c(10,10,10,10,10),
                            endCol = c(36,36,36,36,36)
)



# Assigment 1

volumeMining <- convertToDoubleList(as.character(df[[1]]))
volumeWaterSupply <- convertToDoubleList(as.character(df[[2]]))

constructTheVolumePlot(volumeMining, "Mining Production")
constructTheVolumePlot(volumeWaterSupply,"Water supply and Treatment Production")

volumeTotal <- as.character(df[[5]])
volumeTotal <- convertToDoubleList(volumeTotal)

constructTheVolumePlot(volumeTotal,"Total production")

shareOfDifference <- (volumeMining - volumeWaterSupply) / volumeTotal * 100

constructTheSharePlot(shareOfDifference, "Difference of shares of mining and water supply production")

shapiro.test(shareOfDifference)
# p-value = 0.9227, reject Normal Distribution

print(t.test(shareOfDifference, conf.level=0.9))
# Answer CI = [2.527357, 3.437553]


# Assigment 2

volumeEnergy <-convertToDoubleList(as.character(df[[4]]))
volumeManuf <-convertToDoubleList(as.character(df[[3]]))

constructTheVolumePlot(volumeEnergy, "Production and distribution of electricity gas and water")
constructTheVolumePlot(volumeManuf, "Manufacture Production")

shareOfVolumeSum <- (volumeEnergy + volumeManuf) / volumeTotal * 100  

constructTheSharePlot(shareOfVolumeSum,"The total share of manufacture and energy production")
     

shapiro.test(shareOfVolumeSum)
# p-value = 0.8991 reject Normal Distribution

print(t.test(shareOfVolumeSum, alternative ="greater",mu=95))
# p-value - 0.367 > 0.1 fail to reject H0




