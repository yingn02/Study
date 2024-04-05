%%양자화

x = imread('newborn.tif');

%%2
f1 = floor(double(x)/2); %%종류를 줄이고
q1 = uint8(f1*2); %% 픽셀을 늘림
%%4
f2 = floor(double(x)/4);
q2 = uint8(f2*4);
%%8
f3 = floor(double(x)/8);
q3 = uint8(f3*8);
%%16
f4 = floor(double(x)/16);
q4 = uint8(f4*16);
%%32
f5 = floor(double(x)/32);
q5 = uint8(f5*32);
%%64
f6 = floor(double(x)/64);
q6 = uint8(f6*64);
%%128
f7 = floor(double(x)/128);
q7 = uint8(f7*128);

subplot(2,4,1), imshow(x);
subplot(2,4,2), imshow(q1);
subplot(2,4,3), imshow(q2);
subplot(2,4,4), imshow(q3);
subplot(2,4,5), imshow(q4);
subplot(2,4,6), imshow(q5);
subplot(2,4,7), imshow(q6);
subplot(2,4,8), imshow(q7);


