ig = imread('iguana.tif');
roi = roipoly(ig); %%원하는부분만 뽑아내는 함수

imshow(roi);

%%51p는 마우스말고 정확한 좌표를 정해줄 수 있음