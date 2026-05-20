<?php
require_once '../Model/BookingModel.php';
session_start();

class BookingController {
    public function processBooking() {
        
      
        if (!isset($_SESSION['accountFlag']) || $_SESSION['accountFlag'] == 0) {
            echo "Error: You must register first!";
            return;
        }

        $checkUser = $_POST['checkUser'];
        $checkPass = $_POST['checkPass'];

        if ($checkUser == $_SESSION['regUser'] && $checkPass == $_SESSION['regPass']) {
            echo "Login successful. Enter appointment details:<br>";

            
            $model = new BookingModel();
            $model->patientName = $_POST['patientName'];
            $model->bookDate = $_POST['bookDate'];
            $model->bookTime = $_POST['bookTime'];

            
            $_SESSION['booking_data'] = $model;

            echo "Appointment booked successfully for " . $model->patientName;
        } else {
            echo "Error: Invalid credentials!";
        }
    }
}

// تشغيل الكنترولر تلقائياً عند إرسال الفورم
$controller = new BookingController();
$controller->processBooking();
?>
