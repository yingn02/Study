a=50; sigma=3;
 g=fspecial('gaussian',[a a],sigma);
surf(1:a,1:a,g)
 sigma=9;
 g2=fspecial('gaussian',[a a],sigma);
figure, surf(1:a,1:a,g2)
