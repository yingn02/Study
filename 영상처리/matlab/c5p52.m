a = fspecial('average',[15,15]);
iga = roifilt2(a,ig,roi);
imshow(iga);
u = fspecial('unsharp');
igu = roifilt2(u,ig,roi);
figure, imshow(igu);
l = fspecial('log');
igl = roidfilt2()..