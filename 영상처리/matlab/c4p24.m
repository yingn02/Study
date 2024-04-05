t = imread('tire.tif');
th = imadjust(t,[],[],0.5);
imshow(t),figure,imshow(th);