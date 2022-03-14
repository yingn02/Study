from tkinter import*

def convert():
    f = float(ent.get())
    temp = float(5*(f-32)/9)
    lbl2.configure(text=temp)


root = Tk()
root.title("온도 변환 프로그램_ver1.0")
root.geometry("400x300")

lbl1 = Label(root, text = "화씨", bg = "red")
lbl1.place(x=10,y=10)

ent = Entry(root)
ent.place(x=50,y=10)

btn = Button(root,text = "섭씨로 변환",command = convert)
btn.place(x=50,y=40)

lbl2 = Label(root, text = "섭씨")
lbl2.place(x=50,y=80)


root.mainloop()
