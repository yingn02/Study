p=imread('pelicans.tif');
id=[0 0 0;0 1 0;0 0 0];
f=fspecial('average');
hb1=3*id-2*f;
hb2=1.25*id-0.25*f;
 x1=filter2(hb1,p);
x2=filter2(hb2,p);
figure(1), imshow(p),figure(2), imshow(x1/255),figure(3), imshow(x2/255);
