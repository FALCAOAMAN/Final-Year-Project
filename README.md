# Final Year Project

IOT Based Air Quality Monitoring System Using Machine learning Algorithm

## Software Used 
    1. Arduino Ide : It was used to calibrate MQ135 and MQ2 gas sensor , in interfacing 16X2 LCD ,
                     DHt11 and also to connect with the nearby hotspot

    2. ThingSpeak : ThingSpeak is an IOT analytics platform service that allows to aggregate,
                    visualize and analyse live data streams in the cloud. ThingSpeak provides
                    instant visualizations of data posted by the IOT devices to ThingSpeak server.
    
    3. Jupyter Notebook : Jupyter Notebook (formerly IPython Notebooks) is a web-based interactive 
                          computational environment for creating Jupyter notebook documents.        


## Hardware Used
   
    1. Arduino Uno 
   <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/Uno.png" width="400" height="400">

   
    2. Wifi Module (ESP8266)
   ![wifi](https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/wifi.png)
   
    3. 16X2 LCD Display
   ![LCD](https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/LCD.png)
   
    4. Sensors (MQ135,MQ2,DHT11)
 
   <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MQ135.png" width="400" height="200">  <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MQ2.png" width="200" height="200"> <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/DHT11.png" width="200" height="200">
   
   ## Circuit Diagram
![Circuit Diagram](https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/cIRCUIT%20dIAGRAM.JPG)

## Working Principle 

The data that was collected from the sensors were directly downloaded as the csv file using Python codes
using Serial Library and then we trained our model in Jupyter Notebook using VAR Model Formula.
Autoregression models, the time series is modeled as a linear combination of it’s own lags. That is, the
past values of the series are used to forecast the current and future.
A typical AR(p) model equation looks something like this:

    y_t=α+β_1 y_(t-1)+β_2 y_(t-2)+⋯+β_p y_(t-p)+ϵ_t

where α is the intercept, a constant and β1, β2 till βp are the coefficients of the lags of Y till order p.

Order ‘p’ means, up to p-lags of Y is used and they are the predictors in the equation. The ε_{t} is the error, 
which is considered as white noise.
Steps to build a VAR Model :

    a)	Analyze the time series characteristics
    b)	Test for causation amongst the time series
    c)	Test for stationarity
    d)	Transform the series to make it stationary, if needed
    e)	Find optimal order (p)
    f)	Prepare training and test datasets
    g)	Train the model
    h)	Roll back the transformations, if any.
    i)	Evaluate the model using test set
    j)	Forecast to future

## Results
1. ### ThingSpeak Readings
 <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/CO.png" width="700" height="500"> <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/temp.JPG" width="300" height="200"> <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/Air%20quality%20monitoring%20-%20ThingSpeak%20IoT%20-%20Google%20Chrome%2010-02-2021%2016_37_24%20(2).png" width="300" height="200">

 2. ### Data Analysis using Matplotlib and Seaborn
 <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/AREAPLOT.JPG" width="300" height="300"> 
 
     This plot shows the data for every data point over a period of time. We can also see that PPM levels
     and temperature were high on some days and dipped on some as the sensors were kept on different places 
     and on different days. The highs and dips for CO2, CO and AQI coincided which is a major point to note.
 
 <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MEANAQI.JPG" width="300" height="300"> <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MEANCO.JPG" width="300" height="300"> 
 <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MEANCO2.JPG" width="300" height="300">  <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/MEANTEMP.JPG" width="300" height="300"> 
 
    These plots suggests the median of data in each day. From these plots we can see that AQI median on each
    day is less then 50 which is a very good thing but still we need to take care as on some places it exceeded 
    100 while the data was taken on Thursday while stuck on a traffic jam.
    
 <img src="https://github.com/FALCAOAMAN/Final-Year-Project/blob/main/ProjectPics/Acc.png" width="300" height="300"> 
 
     As we can see the mape (Mean Absolute Percentage Error) of each predicted value is less than 10% which suggests 
     that the predicted values are quite accurate.
 
 ## Conclusions
 
    From all the above information provided , we are able to calculate the AirQuality in PPM. The main advantage of having
    MQ135 and MQ2 is that they collectively detect CO2, CO, NH4, Smoke, LPG and few more. This paper also corrects the PPM 
    calculations mentioned at Literature Review. The model can be used for both indoor as well as outdoor and the fact that 
    it is so compact that we can take it anywhere and it just cost us so less making it the cheapest in the market.
    The difference in the accuracy comes while calibrating the MQ sensors. Enough care was taken while calculating the Rs/Ro
    because the sensors had to be kept in the cleanest of air to make our model as accurate as possible. Our paper also targets 
    the Machine Learning analysis on the dataset collected.
    The best choice we found to train the model was Vector Auto Regression Model (VAR) . A VAR model is used for multivariate 
    time series analysis. The whole structure is that the variable is a linear function of the past lags of the current variable
    with the past lags of the other variables. Many model were tested and even an Long Short Term Memory Model (LSTM) was considered 
    and it was found that the VAR gave the best results in the form of Mean Absolute Percentage Error(MAPE) and Root Mean Square
    Error(RMSE).
 
 
    
