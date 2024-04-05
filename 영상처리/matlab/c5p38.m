 p=imread('pelicans.tif');
 u=fspecial('unsharp',0.5);
 pu=filter2(u,p);
 figure(1),imshow(p),figure(2),imshow(pu/255)
