p=imread('pout.tif');
p_st=p;
for i=1:291
    for j=1:240
        if (p(i,j) >=80) & (p(i,j) <=150)
            p_st(i,j)=((250-3)/(150-80))*(p(i,j)-80)+3;
        end
    end
end
 
subplot(1,2,1), imshow(p_st);
subplot(1,2,2),imhist(p_st), axis tight;
