x=imread('buffalo.tif');
f=fspecial('average');
xf=filter2(f,x);
xu=double(x)-xf/1.5;
subplot(1,2,1), imshow(x)
subplot(1,2,2), imshow(xu/70)
