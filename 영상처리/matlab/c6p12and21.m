c = imread('cameraman.tif');
head = c(33:96, 90:153);
imshow(head);

head4n = imresize(head,4,'nearest');
figure, imshow(head4n);

head4b = imresize(head,4,'bilinear');
figure, imshow(head4b);

head4c = imresize(head,4,'bicubic');
figure, imshow(head3c);
