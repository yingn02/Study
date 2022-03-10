from tkinter import *
from tkinter import font

def my_choice():
    if choice.get() == 1:
        lbl_photo.configure(image=photo1)
        lbl_t.configure(text="dog")
        
    elif choice.get() ==2:
        lbl_photo.configure(image=photo2)
        lbl_t.configure(text="cat")
        
    elif choice.get() ==3:
        lbl_photo.configure(image=photo3)
        lbl_t.configure(text="rabbit")
        
    else:
        lbl_photo.configure(image=photo4)
        lbl_t.configure(text="horse")
        
    
root = Tk()
root.title("영어단어 배우기")
root.geometry("600x600")

#font = font.Font(family = "굴림체", size = 14)

choice = IntVar()

lbl1 = Label(root,text="***  동물을 선택하시오 ***", padx = 20,font = "바탕체 18 bold")
lbl1.pack()

rab1 = Radiobutton(root, text="개  ",variable = choice, value = 1,command = my_choice)
rab1.pack()

rab2 = Radiobutton(root, text="고양이", variable = choice, value = 2,command = my_choice)
rab2.pack()

rab3 = Radiobutton(root, text="토끼 ", variable = choice, value = 3,command = my_choice)
rab3.pack()


rab3 = Radiobutton(root, text="말  ",variable = choice, value = 4,command = my_choice)
rab3.pack(padx=5, pady=5)

photo1 = PhotoImage(file="dog.png")
photo2 = PhotoImage(file="cat.png")
photo3 = PhotoImage(file="rabbit.png")
photo4 = PhotoImage(file="horse.png")

                    
lbl_photo = Label(root,text= "사진", image=None)
lbl_photo.pack()


lbl_t = Label(root, text="  ",font = "바탕체 18 bold", fg="red")
lbl_t.pack()

root.mainloop()

