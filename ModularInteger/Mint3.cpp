inline int add(int a, const int& b) { 
	// ensure both arguments are in the range [0, modn)
	a += b;
	if(a >= modn) {
		a -= modn;
	}
	return a;
 }

inline void adds(int& a, const int& b) {
   	a += b;
 	if(a >= modn) {
 		a -= modn;
 	}
}

inline int mul(const int& a, const int& b) { 
	return ((long long) a * b) % modn;
}

inline void muls(int& a, const int& b) {
	a = ((long long) a * b) % modn;
}

template<typename... Args>
inline int add(int a, Args... args) { 
	return add(a, add(args...)); 
}

template<typename... Args>
inline int mul(int a, Args... args) { 
	return mul(a, mul(args...)); 
}

inline int addm(const int& MOD, int a, const int& b) { 
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
	return a;
}

inline int mulm(const int& MOD, const int& a, const int& b) { 
	return ((long long) a * b) % MOD;
}

template<typename... Args>
inline int addm(const int& MOD, int a, Args... args) { 
	return addm(MOD, a, addm(MOD, args...)); 
}

template<typename... Args>
inline int mulm(const int& MOD, int a, Args... args) { 
	return mulm(MOD, a, mulm(MOD, args...)); 
}

int po(int a, int b) {
	int res = 1; 
	while(b > 0) {
		if(b & 1) {
			muls(res, a);
		}
		muls(a, a);
		b >>= 1;
	} 
	return res; 
}

int pom(const int& MOD, int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) {
			res = mulm(MOD, res, a);
		}
		a = mulm(MOD, a, a);
		b >>= 1;
	}
	return res;
}

inline int inv(int a) {
	return po(a, modn - 2);
}