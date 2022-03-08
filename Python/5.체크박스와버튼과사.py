from tkinter import *
from tkinter import font

def sport():
    if choice.get() == 1:
        lbl2.configure(text = "축구")
        imgLabel.configure(image = photo1)  
    elif choice.get() == 2:
        lbl2.configure(text = "야구")
        imgLabel.configure(image = photo2) 
    else:
        lbl2.configure(text = "농구")
        imgLabel.configure(image = photo3)

root = Tk()
root.title("설문조사")
root.geometry("400x400")

choice = IntVar()

font = font.Font(family = "고딕", size=15, slant = "italic", weight = "bold")

lbl1 = Label(root, text = "*** 가장 좋아하는 스포츠를 선택하시오 ***", padx=20, font = font)
lbl1.pack()
lbl2 = Label(root, text = "좋아하는 스포츠",padx=20, fg = "red")
lbl2.pack()

photo1 = PhotoImage(file = "football.png")
photo2 = PhotoImage(file = "baseball.png")
photo3 = PhotoImage(file = "basketball.png")
imgLabel = Label(root, text = "사진보기", width=250, height=250, image = None)
imgLabel.place(x=80, y=110)

rab1 = Radiobutton(root, text = "축구", variable = choice, value=1, command = sport)
rab2 = Radiobutton(root, text = "야구", variable = choice, value=2, command = sport)
rab3 = Radiobutton(root, text = "농구", variable = choice, value=3, command = sport)
rab1.pack()
rab2.pack()
rab3.pack()



root.mainloop()
