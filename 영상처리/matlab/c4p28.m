t=imread('tire.tif');
th=histpwl(t,[0 .25 .5 .75 1], [0 .75 .25 .5 1]);
subplot(2,2,1), imshow(t);
subplot(2,2,3), imshow(th);
subplot(2,2,2),plot(t,th, '.'), axis tight
% histp : piecewise linear transformation
