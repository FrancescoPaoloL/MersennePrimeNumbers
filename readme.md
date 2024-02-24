# Mersenne Prime Numbers
Mersenne primes are a subset of prime numbers that follow a particular pattern, where they can be expressed as "2^p - 1" form (with 'p' as  prime number).
Why this form? When 'p' is a prime number, "2^p" is an even number because it's a power of 2. Subtracting 1 from an even number results in an odd number.

The code besides the trial division method used to check if a number is prime, the code also utilizes the Lucas–Lehmer test (LLT) to determine if a given number is a prime exponent. How it works? 

$$
\text{s}_i = 
\begin{cases}
  4 & \text{if } |i| = 0 \\
  s_{i-1}^2 - 2& \text{otherwise}.
\end{cases}
$$

So if

$$
s_{p-2} \equiv 0 \ (\text{mod} \ M_p)
$$

then the original prime number pp is a prime exponent, suggesting that 

$$
M_p
$$​

could be a Mersenne prime. 

In order to show how this works, we've made a simple C program that check if a given number is prime and if it's a prime exponent, which is a necessary condition for a Mersenne prime about first 1M numbers.


## Languages and Tools
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)


## Requirements
To build and run this project, you'll need:
- CMake

## Building the Project
Follow these steps to build the project using CMake:
1. Clone the repository to your local machine: git clone https://github.com/...
2. Navigate to the project directory: cd your-repository
3. Create a build directory: mkdir build --> cd build
4. Generate the build files using CMake: cmake ..
5. Build the project using the appropriate build tool (e.g., make): make

After following these steps, you should find the compiled executable in the build directory. You can run the executable to execute the program.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

<hr>

## Connect with me
<p align="left">
<a href="https://www.linkedin.com/in/francescopl/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="francescopaololezza" height="20" width="30" /></a>
<a href="https://www.kaggle.com/francescopaolol" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/kaggle.svg" alt="francescopaololezza" height="20" width="30" /></a>
</p>

