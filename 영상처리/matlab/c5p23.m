c=imread('cameraman.tif');
f=fspecial('laplacian');
f=fspecial('laplacian')
f =

    0.1667    0.6667    0.1667
    0.6667   -3.3333    0.6667
    0.1667    0.6667    0.1667
cf=filter2(f,c);
imshow(cf/100)
f1=fspecial('log')
f1 =

    0.0448    0.0468    0.0564    0.0468    0.0448
    0.0468    0.3167    0.7146    0.3167    0.0468
    0.0564    0.7146   -4.9048    0.7146    0.0564
    0.0468    0.3167    0.7146    0.3167    0.0468
    0.0448    0.0468    0.0564    0.0468    0.0448

cf1=filter2(f1,c);
figure,imshow(cf1/100)
