# Code written by Breeanna Watters, Undergrad Student
# Code created to reconize text in an image
# Results are not always acurate
##you will need to change 2 things to get the code to work for you
## The things that needs changed are image_dir and the tesseract cmd line
## these things are on lines 55 and 58

import csv 
# to mess with csv files

import os
# to read file directeries

import cv2
#to mess with the images

import copy
#to copy files around

import pytesseract as tess
#to image process

import numpy as np 
# to do some processing of images


# get grayscale image
def get_grayscale(image):
    return cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# to make picture blavk and white


# noise removal
def remove_noise(image):
    return cv2.medianBlur(image,5)
#to smooth images
 
#dilation
def dilate(image):
    kernel = np.ones((5,5),np.uint8)
    return cv2.dilate(image, kernel, iterations = 1)
#adds white pixels to the image
 
#erosion
def erode(image):
    kernel = np.ones((5,5),np.uint8)
    return cv2.erode(image, kernel, iterations = 1)
#makes the file more pixalated

#canny edge detection
def canny(image):
    return cv2.Canny(image, 100, 200)
#to make black and white lines

tess.pytesseract.tesseract_cmd = r"C:\Users\watte\AppData\Local\Tesseract-OCR\tesseract.exe"
#code to change for the location of Tesseract_OCR\tesseract.exe
 
image_dir = "C:/Users/watte/OneDrive/Documents/Engineering/ECE 449/Project 1/pfw images/pfw images"
#location of pictures
   
Pictures = os.listdir(image_dir) 
#makes list of pictures in directory

Number= len(Pictures)
#number of images in directory

path_1 = [f'{image_dir}\{i}' for i in Pictures]
#puts paths of pictures in path_1

Image_Vari = [None]*Number
Image_B = [None]*Number
# random arrays for some image processing


for x in range(Number):
    path = path_1[x]
    Image_Vari[x] = cv2.imread(path)    
#read images in directory at the path into random array

for x in range(Number):
    Image_B[x] = copy.deepcopy(Image_Vari[x])    
    Image_B [x]= cv2.resize(Image_B[x], (600,360))
#copy images into array for showing images at the end

for x in range(Number):
    Image_Vari[x] =cv2.resize(Image_Vari[x], (600, 360))
#to resize image for better viewing

#    Image_Vari[x]=remove_noise(Image_Vari[x])
##made the letters to smooth and combine together.

#    Image_Vari[x]=dilate(Image_Vari[x])
## Hard to read small text or thin text

    Image_Vari[x]=get_grayscale(Image_Vari[x])
#image goes black and white

#    Image_Vari[x]=erode(Image_Vari[x])
##Not really good bolded the letters making really hard to read
 
    Image_Vari[x]=canny(Image_Vari[x])
#Made them text into bubble letters in black form

Image_After = [None]*Number
First_Processed_Img = [None]*Number
Text_Out = [None]*Number
Random=[None]*Number
#some more arrays for image storing/editing and text

for x in range(Number):
    Random[x] = tess.image_to_data(Image_Vari[x])
    Temp = tess.image_to_string(Image_Vari[x])
    Text_Out[x] = Temp.split()
    print('For Image "', Pictures[x], '" the output text is', Text_Out[x] ,'.....!!end of text!!.....')
    if Text_Out[x] == []:
        Text_Out[x] = ['No Text Recognized']
    Text_Out[x].insert(0,Pictures[x])
#Reads the text in the images and prints them to the side 
#also makes the some text if no text is detected in the images

with open('Pictures_with_Text_0.csv', 'w') as f:
    print("File Created Successfully")
    writer = csv.writer(f)
    for i in range (Number):
        writer.writerow(Text_Out[i])
f.close()
print("Output file Completed")
#writes text and image names into a csv file and prints when complete

for x in range(Number):
    cv2.imshow(f'{Pictures[x]}_Before', Image_B[x])
    cv2.waitKey(0)
    cv2.imshow(f'{Pictures[x]}_After', Image_Vari[x])
    cv2.waitKey(0)
print('Program is Complete')
#opens the pictures in a new window. The images have to images, the first is not changed,
#the second is how it was after editing.