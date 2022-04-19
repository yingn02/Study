from tkinter import *

def r_area():
    ent2.delete(0,END)
    r = int(ent1.get())
    area = 3.14 * r * r
    ent2.insert(0,area)

def r_circum():
    ent3.delete(0,END)
    r= int(ent1.get())
    circum = 2 * 3.14 * r
    ent3.insert(0,circum)
    
def delete():
    ent1.delete(0,END)
    ent2.delete(0,END)
    ent3.delete(0,END)
    
    

# 윈도우 부모 창 만들기
window  = Tk()         
window.title("원의넓이/둘레 구하기")
window.geometry("600x400")

# 레이블 만들기
lbl1 = Label(window, text = "원의 반지름을 입력하세요=>",
             font = ("굴림체",13))
lbl1.grid(row = 0, column = 0)

# 텍스트 입력 상자 만들기
ent1 = Entry(window)
ent1.grid(row = 0, column = 1)

#원의 넓이 버튼과 원의 넓이 결과 텍스트 상자 만들기
btn1 = Button(window, text = "원의넓이", width=20, height = 2, command = r_area)
btn1.grid(row = 1, column = 0)

ent2 = Entry(window)
ent2.grid(row = 1, column = 1)

#원의 둘레 버튼과 원의 둘레 결과 텍스트 상자 만들기
btn2 = Button(window, text = "원의둘레", width=20, height = 2, command = r_circum)
btn2.grid(row = 2, column = 0)

ent3 = Entry(window)
ent3.grid(row = 2, column = 1)

#지우기 버튼 만들기
btn3 = Button(window, text = "지우기", bg ="gray", fg="white", width=20, height = 2,
              command = delete)
btn3.grid(row = 3, column = 0)

#이미지 넣기
img = PhotoImage(file="원.png")
lbl2 = Label(window, image = img)
lbl2.grid(row = 3, column = 1)


window.mainloop()
