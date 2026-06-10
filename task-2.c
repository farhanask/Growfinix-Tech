# Weather App using Tkinter and OpenWeatherMap API
import tkinter as tk
from tkinter import messagebox
import requests
# Replace with your OpenWeatherMap API key
API_KEY = "YOUR_API_KEY"
# Function to get weather details
def get_weather():
    city = city_entry.get()
    if city == "":
        messagebox.showwarning("Warning", "Please enter city name")
        return
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}&units=metric"
    try:
        response = requests.get(url)
        data = response.json()
        if data["cod"] != 200:
            messagebox.showerror("Error", "City not found")
            return
        temp = data["main"]["temp"]
        humidity = data["main"]["humidity"]
        description = data["weather"][0]["description"]
        result_label.config(
            text=f"Temperature: {temp}°C\n"
                 f"Humidity: {humidity}%\n"
                 f"Weather: {description}"
        )
    except:
        messagebox.showerror("Error", "Failed to fetch weather data")
# Main window
root = tk.Tk()
root.title("Weather App")
root.geometry("400x300")
# Title
title = tk.Label(root, text="Weather App", font=("Arial", 20))
title.pack(pady=10)
# City input
city_entry = tk.Entry(root, font=("Arial", 14))
city_entry.pack(pady=10)
# Search button
search_btn = tk.Button(root, text="Search", font=("Arial", 12),
                       command=get_weather)
search_btn.pack(pady=10)
# Result label
result_label = tk.Label(root, text="", font=("Arial", 14))
result_label.pack(pady=20)
# Run app
root.mainloop()