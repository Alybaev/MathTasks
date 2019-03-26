
# Assigment 1
volumeMining <-c(296.4,267.8,286.0,492.1,366.0,307.2,433.3,480.7,686.6,604.8,647.6,808.1,845.6,237.2,683.6,473.7,627.5,761.6,503.2,745.2,776.8,516.8)

volumeWaterSupply <- c(126.1,111.4,120.5,114.5,112.1,119.3,131.0,128.0,125.0,123.6,128.7,133.9, 123.9,118.6,130.4,127.3,117.8,130.7,131.6,131.7,136.7,133.7)

volumeDifference <- volumeMining - volumeWaterSupply

volumeTotal <- c(10720.7, 12563.8, 10937.9, 10364.0, 9907.4, 11357.5, 9877.4, 10892.0, 14327.9, 18330.0, 22679.9, 25280.4,17973.9,16363.3,16284.4,13457.2,12793.7,12778.1,12714.6,12829.5,11559.4,14012.2)

volumeWithRespectTotal <- (volumeDifference / volumeTotal) * 100

shapiro.test(volumeWithRespectTotal)

t.test(volumeWithRespectTotal,conf.level=0.9)
# Answer CI = [2.527357, 3.437553]

# Assigment 2

volumeEnergy <- c(3110.8,3046.2,2610.1,1715.6,1130.0,1032.2,1155.5,1070.0,1223.9,1486.4,2445.1,3186.1, 4012.8,3966.9,3253.4,2180.8,1498.5,1471.9,1583.1,1552.7,1634.1,2097.7)
volumeManuf <- c(7187.3,9138.5,7921.1,8042.0,8299.1,9899.0,8157.5,9084.6,12421.2,16115.2,19458.5,21152.2, 12991.6,12040.6,12216.9,10675.4,10549.9,10413.9,10496.6,10399.8,9011.8,11263.9)

volumeSum <-  volumeEnergy + volumeManuf

#partialTotal 292604 < volume sum 293400
partialTotalVolume <- volumeSum / volumeTotal * 100  

shapiro.test(partialTotalVolume)
# p-value = 0.8991 reject Normal Distribution
t.test(partialTotalVolume, alternative ="greater",mu=95)

