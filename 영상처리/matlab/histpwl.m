function out=histpwl(im, a,b) % a,b 는 행렬
 
classChanged=0; %flag값, classChanged=1: Double 에 대한 flag 값.
if ~isa(im, 'double'), % image 데이터가 double 이 아니라면
    classChanged =1; % Double 에 대한 flag 값.
    im=im2double(im); % data 형은 double로 바뀌고 값은 0.0~1.0
end
 
if length(a) ~= length(b) %두 행렬의 길이가 다르면 연산 안됨    
    error('Vectors A and B must be of equal size');
end

N=length(a);
out=zeros(size(im)); %입력 영상의 크기와 동일한 출력 영상 out을 생성하고 ‘0’ 으로 초기화
 for i=1:N-1
    pix=find(im >=a(i) & im < a(i+1)); %pix는 index 행렬
    out(pix)=(im(pix)-a(i))*(b(i+1)-b(i))/(a(i+1)-a(i)) +b(i);
end
 
pix=find(im == a(N)); %마지막 N번째는 입출력 모두 1 이므로  
out(pix)=b(N); %연산이 필요 없이 입력과 동일한 출력 생성
 
if classChanged == 1 %double  이라면
    out= uint8(255*out); % 출력과 display를 위해 0~255 사이의 정수로 바꿈
end
