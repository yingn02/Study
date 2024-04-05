%%디더링

x = imread('newborn.tif');
x = double(x);

D = [0 128; 192 64];
r = repmat(D,128,128);
x2 = x > r; 
imshow(x2)

D2 = [0 128 32 160; 192 64 224 96; 48 176 16 144; 240 112 208 80];
r2 = repmat(D2,64,64);
x4 = x > r2;
figure, imshow(x4)