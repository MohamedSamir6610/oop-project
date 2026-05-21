<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Dental Clinic - Register</title>
</head>
<body>
    <h2>Register Page</h2>
    
    <form action="../Control/RegisterController.php" method="POST">
        <label>Enter username:</label>
        <input type="text" name="inputUser" required><br><br>
        
        <label>Enter password:</label>
        <input type="password" name="inputPass" required><br><br>
        
        <button type="submit">Register</button>
    </form>
</body>
</html>
