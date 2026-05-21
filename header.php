<?php 
if (session_status() === PHP_SESSION_NONE) {
    session_start(); 
}
?>
<div class="navbar2">
    <div class="logo">
        <img src="ff.jpeg" alt="Seryana Logo" class="logo-img">
    </div>

    <div class="nav-links">
        <a href="home.php">Home</a>
        <a href="about.php" class="active">About us</a>
        <a href="service.php">Service</a>
        
        <?php if(isset($_SESSION['user_id'])): ?>
            <a href="medicalrecord.php">Medical Record</a>
            <a href="profile.php">My Profile</a>
            <a href="contactus.php">Contact us</a>
        <?php else: ?>
            <a href="contactus.php">Contact us</a>
        <?php endif; ?>
    </div>

    <?php if(isset($_SESSION['user_id'])): ?>
        <a href="bookappoinment.php" class="login-btn">Book Appointment</a>
    <?php else: ?>
        <a href="login.php" class="login-btn">Log in</a>
    <?php endif; ?>
</div>