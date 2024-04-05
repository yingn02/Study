c = imread('cameraman.tif');

cr = imrotate(c,60);
imshow(cr);
crc = imrotate(c,60,'bicubic');
figure, imshow(crc);