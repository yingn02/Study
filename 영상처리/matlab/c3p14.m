c = imread('cameraman.tif');
cd = double(c);

c0 = mod(cd,2);
c1 = mod(floor(cd/2), 2);
c2 = mod(floor(cd/4), 2);
c3 = mod(floor(cd/8), 2);
c4 = mod(floor(cd/16), 2);
c5 = mod(floor(cd/32), 2);
c6 = mod(floor(cd/64), 2);
c7 = mod(floor(cd/128), 2);

imshow(c0)
figure,imshow(c1)
figure,imshow(c2)
figure,imshow(c3)
figure,imshow(c4)
figure,imshow(c5)
figure,imshow(c6)
figure,imshow(c7)
