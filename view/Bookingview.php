<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Book Appointment</title>
</head>
<body>
    <h2>Book Appointment Page</h2>
    
    <form action="../Control/BookingController.php" method="POST">
        
        <h3>Confirm Identity</h3>
        <label>Confirm Username:</label>
        <input type="text" name="checkUser" required><br><br>
        
        <label>Confirm Password:</label>
        <input type="password" name="checkPass" required><br><br>
        
        <h3>Appointment Details</h3>
        <label>Patient Name:</label>
        <input type="text" name="patientName" required><br><br>
        
        <label>Date (YYYY-MM-DD):</label>
        <input type="date" name="bookDate" required><br><br>
        
        <label>Time (e.g. 05:00PM):</label>
        <input type="text" name="bookTime" required><br><br>
        
        <button type="submit">Book Appointment</button>
    </form>
</body>
</html>
