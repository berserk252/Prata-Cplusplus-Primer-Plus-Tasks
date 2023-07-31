#ifndef E1
#define E1
	class Cd{
		private:
			char *performers;
			char *label;
			int selection;
			double playtime;
		public:
			Cd(char *s1, char * s2, int n, double x);
			Cd(const Cd & d);
			Cd();
			virtual ~Cd();
			virtual void Report() const;
			Cd & operator=(const Cd & d);
	};
	
	class Classic :public Cd
	{
		private:
			char *song;
		public:
			Classic(char *so, char *s1, char * s2, int n, double x);
			Classic(const Classic & d);
			Classic();
			virtual ~Classic();
			virtual void Report() const;
			Classic & operator=(const Classic & d); 
	};
#endif
