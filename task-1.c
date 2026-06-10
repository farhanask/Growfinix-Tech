import tkinter as tk
from tkinter import messagebox
import math
# Function to add values to display
def click(value):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(tk.END, current + str(value))
# Function to clear display
def clear():
    entry.delete(0, tk.END)
# Function to calculate result
def calculate():
    try:
        expression = entry.get()
        result = eval(expression)
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))
    except ZeroDivisionError:
        messagebox.showerror("Error", "Division by zero is not allowed")
        clear()
    except:
        messagebox.showerror("Error", "Invalid Input")
        clear()
# Function for square root
def square_root():
    try:
        value = float(entry.get())
        result = math.sqrt(value)
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))
    except:
        messagebox.showerror("Error", "Invalid Input")
# Function for percentage
def percentage():
    try:
        value = float(entry.get())
        result = value / 100
        entry.delete(0, tk.END)
        entry.insert(tk.END, str(result))
    except:
        messagebox.showerror("Error", "Invalid Input")
# Create main window
root = tk.Tk()
root.title("Basic Calculator")
root.geometry("350x450")
root.resizable(False, False)
# Entry widget for display
entry = tk.Entry(root, font=("Arial", 20), bd=10, relief=tk.RIDGE, justify="right")
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)
# Button layout
buttons = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('0', 4, 0), ('.', 4, 1), ('=', 4, 2), ('+', 4, 3),
]
# Create buttons
for (text, row, col) in buttons:
    if text == '=':
        btn = tk.Button(root, text=text, width=8, height=3,
                        command=calculate)
    else:
        btn = tk.Button(root, text=text, width=8, height=3,
                        command=lambda t=text: click(t))

    btn.grid(row=row, column=col, padx=5, pady=5)
# Clear button
clear_btn = tk.Button(root, text="Clear", width=17, height=3, command=clear)
clear_btn.grid(row=5, column=0, columnspan=2, padx=5, pady=5)
# Square Root button
sqrt_btn = tk.Button(root, text="√", width=8, height=3, command=square_root)
sqrt_btn.grid(row=5, column=2, padx=5, pady=5)
# Percentage button
percent_btn = tk.Button(root, text="%", width=8, height=3, command=percentage)
percent_btn.grid(row=5, column=3, padx=5, pady=5)
# Keyboard input support
root.bind("<Return>", lambda event: calculate())
root.bind("<Escape>", lambda event: clear())
# Run application
root.mainloop()