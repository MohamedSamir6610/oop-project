<?php
class BookingModel {
    public $patientName;
    public $bookDate;
    public $bookTime;

    public function __construct() {
        $this->patientName = "";
        $this->bookDate = "";
        $this->bookTime = "";
    }
}
?>
