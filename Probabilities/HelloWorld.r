#Confidence interval for mean (p.2, ex.9)

ret<-c(11.1, 12.5, 13.6, 9.1,8.7, 10.6, 12.5, 15.6, 13.8, 8.0, 10.9, 7.6, 5.2, 1.2, 12.8, 16.7, 13.9, 10.1, 9.6, 10.8, 11.6, 12.3, 12.9, 11.6)
# Test for normality p = 0.1501

shapiro.test(ret)

t.test(ret,conf.level=0.9)


# Hypothesis testing: H0
t.test(ret, alternative ="less",mu=9)
