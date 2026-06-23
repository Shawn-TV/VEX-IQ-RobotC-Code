
#pragma config(Sensor, port3,  color,          sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor1,          leftmotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          rightmotor,    tmotorVexIQ, PIDControl, reversed, encoder)

task main()
{

	setMotorSpeed(leftmotor, 50);
	setMotorSpeed(rightmotor, 50);
	sleep(2000);

	while(getMotorEncoder(leftmotor)<2800)
	{
		if(getColorValue(color) < 180)
		{

			setMotorSpeed(leftmotor, 0);
			setMotorSpeed(rightmotor, 60);
		}
		else
		{

			setMotorSpeed(leftmotor, 60);
			setMotorSpeed(rightmotor, 0);
		}
	}

		while(getMotorEncoder(leftmotor)>=2800)
	{
		if(getColorValue(color) < 180)
		{

			setMotorSpeed(leftmotor, 60);
			setMotorSpeed(rightmotor, 0);
		}
		else
		{

			setMotorSpeed(leftmotor, 0);
			setMotorSpeed(rightmotor, 60);
		}
	}

}
