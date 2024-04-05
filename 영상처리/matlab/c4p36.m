p = imread('pout.tif');
ph = histeq(p);
imshow(ph), figure, imhist(ph), axis tight