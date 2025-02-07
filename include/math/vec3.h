class Vec3 {
    public:
    float x;
    float y;
    float z;

    Vec3 operator+(const Vec3& term) const;
    Vec3 operator-(const Vec3& term) const;
    Vec3 operator*(const Vec3& term) const;
    Vec3 operator/(const Vec3& term) const;
    Vec3 operator%(const Vec3& term) const;
    bool operator<=>(const Vec3& term) const;

    float dot(const Vec3& term) const;
    float length() const;

    Vec3 cross(const Vec3& term) const;
    Vec3 normalise() const;
    Vec3 reflect() const;

    private:
};