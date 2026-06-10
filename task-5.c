# Email Sender App using Python
import smtplib
from email.message import EmailMessage
import getpass
# Function to send email
def send_email():
    # User Inputs
    sender_email = input("Enter sender email: ")
    password = getpass.getpass("Enter app password: ")
    recipients = input("Enter recipient emails (comma separated): ")
    recipient_list = recipients.split(",")
    subject = input("Enter subject: ")
    body = input("Enter message: ")
    # Validate fields
    if sender_email == "" or recipients == "" or subject == "" or body == "":
        print("Error: All fields are required")
        return
    try:
        # Create email message
        msg = EmailMessage()
        msg["From"] = sender_email
        msg["To"] = ", ".join(recipient_list)
        msg["Subject"] = subject
        msg.set_content(body)
        # Connect to Gmail SMTP server
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        # Login
        server.login(sender_email, password)
        # Send email
        server.send_message(msg)
        # Close server
        server.quit()
        print("Email sent successfully!")
    except smtplib.SMTPAuthenticationError:
        print("Login failed! Check email or password.")
    except Exception as e:
        print("Error:", e)
# Run program
send_email()