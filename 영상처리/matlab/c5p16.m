c = imread("cameraman.tif");

f1 = fspecial('average');
f2 = fspecial('average', 9);
f3 = fspecial('average', 25);

cf1 = filter2(f1, c);
cf2 = filter2(f2, c);
cf3 = filter2(f3, c);

imshow(cf1/255);
figure, imshow(cf2/255);
figure, imshow(cf3/255);